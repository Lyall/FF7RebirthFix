#include "stdafx.h"
#include "helper.hpp"

#include "SDK/Engine_classes.hpp"
#include "SDK/Pause_00_classes.hpp"
#include "SDK/Com_Window_01_classes.hpp"
#include "SDK/AreaMap_TopBase_classes.hpp"
#include "SDK/VR_Top_classes.hpp"
#include "SDK/BattleTips_classes.hpp"
#include "SDK/Subtitle00_classes.hpp"
#include "SDK/MainMenu_Top_Window_classes.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <inipp/inipp.h>
#include <safetyhook.hpp>

#define spdlog_confparse(var) spdlog::info("Config Parse: {}: {}", #var, var)

HMODULE exeModule = GetModuleHandle(NULL);
HMODULE thisModule;

// Fix details
std::string sFixName = "FF7RebirthFix";
std::string sFixVersion = "0.0.10";
std::filesystem::path sFixPath;

// Ini
inipp::Ini<char> ini;
std::string sConfigFile = sFixName + ".ini";

// Logger
std::shared_ptr<spdlog::logger> logger;
std::string sLogFile = sFixName + ".log";
std::filesystem::path sExePath;
std::string sExeName;

// Aspect ratio / FOV / HUD
std::pair DesktopDimensions = { 0,0 };
const float fPi = 3.1415926535f;
const float fNativeAspect = 1.7777778f;
float fAspectRatio;
float fAspectMultiplier;
float fHUDWidth;
float fHUDWidthOffset;
float fHUDHeight;
float fHUDHeightOffset;
float fHUDScale;

// Ini variables
bool bFixAspect;
bool bFixHUD;
bool bFixMovies;
float fFramerateLimit = 120.00f;
bool bGlobalFOVMulti;
float fFOVMulti;
bool bDynamicFOVChanger;
bool bAutoVignette;
float fVignetteStrength;
float fHUDResScale;
int iCustomResX;
int iCustomResY;
float fSubtitleScale;
bool bShadowDistTweak;
int iShadowResolution;

// Variables
int iCurrentResX;
int iCurrentResY;
int iCompositeLayerX = 1920;
int iCompositeLayerY = 1080;
int iPrevCompositeLayerX;
int iPrevCompositeLayerY;
bool bMovieIsPlaying = false;
int iScreenMode;
bool bHUDNeedsResize = false;

// HUD Widgets
SDK::USubtitle00_C* UMGSubtitles = nullptr;
SDK::UPause_00_C* UMGPauseMenu = nullptr;
SDK::UCom_Window_01_C* UMGComWindow = nullptr;
SDK::UAreaMap_TopBase_C* UMGAreaMap = nullptr;
SDK::UVR_Top_C* UMGVRTop = nullptr;
SDK::UBattleTips_C* UMGBattleTips = nullptr;
SDK::UMainMenu_Top_Window_C* UMGMainMenu = nullptr;

// Function pointers
std::uint8_t* GameplayFOVScanResult = nullptr;
std::uint8_t* GameplayFOVAltScanResult = nullptr;
std::uint8_t* AspectRatioFOVScanResult = nullptr;

SafetyHookMid FOVMidHook{};
SafetyHookMid AspectRatioMidHook{};
SafetyHookMid GameplayFOVMidHook{};
SafetyHookMid GameplayFOVAltMidHook{};

void Logging()
{
    // Get path to DLL
    WCHAR dllPath[_MAX_PATH] = { 0 };
    GetModuleFileNameW(thisModule, dllPath, MAX_PATH);
    sFixPath = dllPath;
    sFixPath = sFixPath.remove_filename();

    // Get game name and exe path
    WCHAR exePath[_MAX_PATH] = { 0 };
    GetModuleFileNameW(exeModule, exePath, MAX_PATH);
    sExePath = exePath;
    sExeName = sExePath.filename().string();
    sExePath = sExePath.remove_filename();

    // Spdlog initialisation
    try {
        logger = spdlog::basic_logger_st(sFixName.c_str(), sExePath.string() + sLogFile, true);
        spdlog::set_default_logger(logger);
        spdlog::flush_on(spdlog::level::debug);

        spdlog::info("----------");
        spdlog::info("{:s} v{:s} loaded.", sFixName.c_str(), sFixVersion.c_str());
        spdlog::info("----------");
        spdlog::info("Log file: {}", sFixPath.string() + sLogFile);
        spdlog::info("----------");
        spdlog::info("Module Name: {0:s}", sExeName.c_str());
        spdlog::info("Module Path: {0:s}", sExePath.string());
        spdlog::info("Module Address: 0x{0:x}", (uintptr_t)exeModule);
        spdlog::info("Module Timestamp: {0:d}", Memory::ModuleTimestamp(exeModule));
        spdlog::info("----------");
    }
    catch (const spdlog::spdlog_ex& ex) {
        AllocConsole();
        FILE* dummy;
        freopen_s(&dummy, "CONOUT$", "w", stdout);
        std::cout << "Log initialisation failed: " << ex.what() << std::endl;
        FreeLibraryAndExitThread(thisModule, 1);
    }  
}

void Configuration()
{
    // Inipp initialisation
    std::ifstream iniFile(sFixPath / sConfigFile);
    if (!iniFile) {
        AllocConsole();
        FILE* dummy;
        freopen_s(&dummy, "CONOUT$", "w", stdout);
        std::cout << "" << sFixName.c_str() << " v" << sFixVersion.c_str() << " loaded." << std::endl;
        std::cout << "ERROR: Could not locate config file." << std::endl;
        std::cout << "ERROR: Make sure " << sConfigFile.c_str() << " is located in " << sFixPath.string().c_str() << std::endl;
        spdlog::error("ERROR: Could not locate config file {}", sConfigFile);
        spdlog::shutdown();
        FreeLibraryAndExitThread(thisModule, 1);
    }
    else {
        spdlog::info("Config file: {}", sFixPath.string() + sConfigFile);
        ini.parse(iniFile);
    }

    // Parse config
    ini.strip_trailing_comments();
    spdlog::info("----------");

    // Load settings from ini
    inipp::get_value(ini.sections["Framerate"], "FPS", fFramerateLimit);
    inipp::get_value(ini.sections["FOV"], "Global", bGlobalFOVMulti);
    inipp::get_value(ini.sections["FOV"], "Multiplier", fFOVMulti);
	inipp::get_value( ini.sections["FOV"], "DynamicChanger", bDynamicFOVChanger );
    inipp::get_value(ini.sections["Subtitles"], "Size", fSubtitleScale);

    inipp::get_value(ini.sections["Custom Resolution"], "Width", iCustomResX);
    inipp::get_value(ini.sections["Custom Resolution"], "Height", iCustomResY);
    inipp::get_value(ini.sections["Fix Aspect Ratio"], "Enabled", bFixAspect);
    inipp::get_value(ini.sections["Fix HUD"], "Enabled", bFixHUD);
    inipp::get_value(ini.sections["Fix HUD"], "ResScale", fHUDResScale);
    inipp::get_value(ini.sections["Fix Movies"], "Enabled", bFixMovies);

    inipp::get_value(ini.sections["Vignette"], "Auto", bAutoVignette);
    inipp::get_value(ini.sections["Vignette"], "Strength", fVignetteStrength);
    inipp::get_value(ini.sections["Shadow Quality"], "Resolution", iShadowResolution);
    inipp::get_value(ini.sections["Shadow Quality"], "TweakDistances", bShadowDistTweak);

    // Clamp settings to avoid breaking things
    fHUDResScale = std::clamp(fHUDResScale, 0.00f, 3.00f);
    fVignetteStrength = std::clamp(fVignetteStrength, 0.00f, 1.00f);
    fSubtitleScale = std::clamp(fSubtitleScale, 0.100f, 2.00f);
    iShadowResolution = std::clamp(iShadowResolution, 64, 16384);

    // Log ini parse
    spdlog_confparse(fFramerateLimit);
    spdlog_confparse(bGlobalFOVMulti);
    spdlog_confparse(fFOVMulti);
    spdlog_confparse(fSubtitleScale);

    spdlog_confparse(iCustomResX);
    spdlog_confparse(iCustomResY);
    spdlog_confparse(bFixAspect);
    spdlog_confparse(bFixHUD);
    spdlog_confparse(fHUDResScale);
    spdlog_confparse(bFixMovies);

    spdlog_confparse(bAutoVignette);
    spdlog_confparse(fVignetteStrength);
    spdlog_confparse(iShadowResolution);
    spdlog_confparse(bShadowDistTweak);

    spdlog::info("----------");
}

void CalculateAspectRatio(bool bLog)
{
    // Calculate aspect ratio
    fAspectRatio = (float)iCurrentResX / (float)iCurrentResY;
    fAspectMultiplier = fAspectRatio / fNativeAspect;

    // Log details about current resolution
    if (bLog) {
        spdlog::info("----------");
        spdlog::info("Current Resolution: Resolution: {:d}x{:d}", iCurrentResX, iCurrentResY);
        spdlog::info("Current Resolution: iScreenMode: {}", iScreenMode);
        spdlog::info("Current Resolution: fAspectRatio: {}", fAspectRatio);
        spdlog::info("Current Resolution: fAspectMultiplier: {}", fAspectMultiplier);
        spdlog::info("----------");
    }

    // Signal for HUD resize
    bHUDNeedsResize = true;
}

void CalculateHUD(bool bLog)
{
    const int MAX_RENDER_TARGET_SIZE = 16384;
    float ResScale = 1.00f;

    if (fHUDResScale == 0.00f) {
        // Calculate a suggested resolution scale
        if (fAspectRatio > fNativeAspect)
            ResScale = fAspectMultiplier;
        else if (fAspectRatio < fNativeAspect)
            ResScale = 1.00f / fAspectMultiplier;
    }
    else {
        // Apply user-defined resolution scale
        ResScale = fHUDResScale;
    }

    // Set render target dimensions
    if (fAspectRatio > fNativeAspect) {
        iCompositeLayerX = iCurrentResX;
        iCompositeLayerY = static_cast<int>(iCurrentResX / fNativeAspect);
    }
    else if (fAspectRatio < fNativeAspect) {
        iCompositeLayerX = static_cast<int>(iCurrentResY * fNativeAspect);
        iCompositeLayerY = iCurrentResY;
    }

    // Apply resolution scale
    iCompositeLayerX = static_cast<int>(iCompositeLayerX * ResScale);
    iCompositeLayerY = static_cast<int>(iCompositeLayerY * ResScale);

    // Don't allow resolution of render target to exceed 8192 on X/Y axis so that people don't kill performance and thrash VRAM
    if (iCompositeLayerX > MAX_RENDER_TARGET_SIZE || iCompositeLayerY > MAX_RENDER_TARGET_SIZE) {
        float scaleFactorX = static_cast<float>(MAX_RENDER_TARGET_SIZE) / iCompositeLayerX;
        float scaleFactorY = static_cast<float>(MAX_RENDER_TARGET_SIZE) / iCompositeLayerY;

        float clampedResScale = std::min(scaleFactorX, scaleFactorY);

        iCompositeLayerX = static_cast<int>(iCompositeLayerX * clampedResScale);
        iCompositeLayerY = static_cast<int>(iCompositeLayerY * clampedResScale);
    }

    // Calculate HUD size and offsets to position HUD within render target
    if (fAspectRatio > fNativeAspect) {
        fHUDWidth = std::ceilf((static_cast<float>(iCompositeLayerX) / fAspectRatio) * fNativeAspect);
        fHUDHeight = std::ceilf(static_cast<float>(iCompositeLayerX) / fAspectRatio);

        fHUDWidthOffset = (static_cast<float>(iCompositeLayerX) - fHUDWidth) / 2.00f;
        fHUDHeightOffset = (static_cast<float>(iCompositeLayerY) - fHUDHeight) / 2.00f;
    }
    else if (fAspectRatio < fNativeAspect) {
        fHUDWidth = std::ceilf(static_cast<float>(iCompositeLayerY) * fAspectRatio);
        fHUDHeight = std::ceilf((static_cast<float>(iCompositeLayerY) * fAspectRatio) / fNativeAspect);

        fHUDWidthOffset = (static_cast<float>(iCompositeLayerX) - fHUDWidth) / 2.00f;
        fHUDHeightOffset = (static_cast<float>(iCompositeLayerY) - fHUDHeight) / 2.00f;
    }

    // Calculate HUD scale
    fHUDScale = std::ceilf((fHUDHeight / 1080.00f) * 1000.00f) / 1000.00f;
    fHUDScale += 0.001f;

    // Log details about current HUD size
    if (bLog) {
        spdlog::info("----------");
        spdlog::info("HUD: Resolution: {}x{} - ResScale: {}", iCompositeLayerX, iCompositeLayerY, ResScale);
        spdlog::info("HUD: fHUDWidth: {}", fHUDWidth);
        spdlog::info("HUD: fHUDHeight: {}", fHUDHeight);
        spdlog::info("HUD: fHUDWidthOffset: {:.2f}", fHUDWidthOffset);
        spdlog::info("HUD: fHUDHeightOffset: {:.2f}", fHUDHeightOffset);
        spdlog::info("HUD: fHUDScale: {:.5f}", fHUDScale);
        spdlog::info("----------");
    }

    // Signal that HUD resize is done
    bHUDNeedsResize = false;
}

void UpdateOffsets()
{
    // GObjects
    std::uint8_t* GObjectsScanResult = Memory::PatternScan(exeModule, "48 8B ?? ?? ?? ?? ?? 48 8B ?? ?? 48 8D ?? ?? EB ?? 33 ??");
    if (GObjectsScanResult) {
        spdlog::info("Offsets: GObjects: Address is {:s}+{:x}", sExeName.c_str(), GObjectsScanResult - (std::uint8_t*)exeModule);
        std::uint8_t* GObjectsAddr = Memory::GetAbsolute(GObjectsScanResult + 0x3);
        SDK::Offsets::GObjects = static_cast<UC::uint32>(GObjectsAddr - (std::uint8_t*)exeModule);
        spdlog::info("Offsets: GObjects: {:x}", SDK::Offsets::GObjects);
    }
    else {
        spdlog::error("Offsets: GObjects: Pattern scan failed.");
    }

    // GNames
    std::uint8_t* GNamesScanResult = Memory::PatternScan(exeModule, "48 8D ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? 4C 8B ?? C6 ?? ?? ?? ?? ?? 01");
    if (GNamesScanResult) {
        spdlog::info("Offsets: GNames: Address is {:s}+{:x}", sExeName.c_str(), GNamesScanResult - (std::uint8_t*)exeModule);
        std::uint8_t* GNamesAddr = Memory::GetAbsolute(GNamesScanResult + 0x3);
        SDK::Offsets::GNames = static_cast<UC::uint32>(GNamesAddr - (std::uint8_t*)exeModule);
        spdlog::info("Offsets: GNames: {:x}", SDK::Offsets::GNames);
    }
    else {
        spdlog::error("Offsets: GNames: Pattern scan failed.");
    }

    // ProcessEvent
    std::uint8_t* ProcessEventScanResult = Memory::PatternScan(exeModule, "40 ?? 56 57 41 ?? 41 ?? 41 ?? 41 ?? B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 ?? ?? 48 8D ?? ?? ?? 48 89 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? 48 89 ?? ?? ?? ?? ?? 8B ?? ?? 45 33 ??");
    if (ProcessEventScanResult) {
        spdlog::info("Offsets: ProcessEvent: Address is {:s}+{:x}", sExeName.c_str(), ProcessEventScanResult - (std::uint8_t*)exeModule);
        SDK::Offsets::ProcessEvent = static_cast<UC::uint32>(ProcessEventScanResult - (std::uint8_t*)exeModule);
        spdlog::info("Offsets: ProcessEvent: {:x}", SDK::Offsets::ProcessEvent);
    }
    else {
        spdlog::error("Offsets: ProcessEvent: Pattern scan failed.");
    }

    spdlog::info("----------");
}

void CurrentResolution()
{
    // Grab desktop resolution
    DesktopDimensions = Util::GetPhysicalDesktopDimensions();

    // Replace 3840x2160 windowed option with desktop resolution
    std::uint8_t* WindowedResListScanResult = Memory::PatternScan(exeModule, "C7 ?? ?? ?? 00 0F 00 00 C7 ?? ?? ?? 70 08 00 00");
    if (WindowedResListScanResult) {
        spdlog::info("Windowed Resolution List: Address is {:s}+{:x}", sExeName.c_str(), WindowedResListScanResult - (std::uint8_t*)exeModule);
        if (iCustomResX <= 0 || iCustomResY <= 0) {
            Memory::Write(WindowedResListScanResult + 0x4, DesktopDimensions.first);
            Memory::Write(WindowedResListScanResult + 0xC, DesktopDimensions.second);
            spdlog::info("Windowed Resolution List: Replaced 3840x2160 with {}x{}", DesktopDimensions.first, DesktopDimensions.second);
        }
        else {
            Memory::Write(WindowedResListScanResult + 0x4, iCustomResX);
            Memory::Write(WindowedResListScanResult + 0xC, iCustomResY);
            spdlog::info("Windowed Resolution List: Replaced 3840x2160 with {}x{}", iCustomResX, iCustomResY);
        }
    }
    else {
        spdlog::error("Windowed Resolution List: Pattern scan failed.");
    }

    // Get current resolution
    std::uint8_t* CurrentResolutionScanResult = Memory::PatternScan(exeModule, "89 ?? ?? ?? ?? ?? 8B ?? 89 ?? ?? ?? ?? ?? 89 ?? ?? ?? ?? ?? C6 ?? ?? ?? ?? ?? 00 E8 ?? ?? ?? ??");
    if (CurrentResolutionScanResult) {
        spdlog::info("Current Resolution: Address is {:s}+{:x}", sExeName.c_str(), CurrentResolutionScanResult - (std::uint8_t*)exeModule);
        static SafetyHookMid CurrentResolutionMidHook{};
        CurrentResolutionMidHook = safetyhook::create_mid(CurrentResolutionScanResult,
            [](SafetyHookContext& ctx) {
                // Read resolution
                int iResX = static_cast<int>(ctx.rsi);
                int iResY = static_cast<int>(ctx.rdi);

                iScreenMode = static_cast<int>(ctx.rbx);

                // If using borderless, use the desktop resolution
                if (iScreenMode == 1) {
                    iResX = DesktopDimensions.first;
                    iResY = DesktopDimensions.second;
                }

                // Log resolution
                if (iResX != iCurrentResX || iResY != iCurrentResY) {
                    iCurrentResX = iResX;
                    iCurrentResY = iResY;
                    CalculateAspectRatio(true);
                }
            });
    }
    else {
        spdlog::error("Current Resolution: Pattern scan failed.");
    }
}

void AspectRatioFOV()
{

    // Aspect ratio / FOV
    AspectRatioFOVScanResult = Memory::PatternScan( exeModule, "C5 FA ?? ?? ?? 8B ?? ?? ?? ?? ?? 89 ?? ?? 0F B6 ?? ?? ?? ?? ?? 33 ?? ?? 83 ?? 01" );

    // Gameplay FOV
    GameplayFOVScanResult = Memory::PatternScan( exeModule, "C5 ?? ?? ?? ?? C5 ?? ?? ?? ?? ?? ?? ?? 45 8B ?? 49 8B ?? BE ?? ?? ?? ??" );
    GameplayFOVAltScanResult = Memory::PatternScan( exeModule, "C4 ?? ?? ?? ?? ?? C4 ?? ?? ?? ?? ?? C4 ?? ?? ?? ?? C4 ?? ?? ?? ?? ?? 41 ?? ?? C5 ?? ?? ?? ?? ?? ?? ?? 45 ?? ?? ?? ?? ?? ??" );

    if (bFixAspect || bGlobalFOVMulti) {
        if (AspectRatioFOVScanResult) {
            spdlog::info("Aspect Ratio/FOV: Address is {:s}+{:x}", sExeName.c_str(), AspectRatioFOVScanResult - (std::uint8_t*)exeModule);
            FOVMidHook = safetyhook::create_mid(AspectRatioFOVScanResult,
                [](SafetyHookContext& ctx) {
                    // Fix vert- FOV when wider than 16:9
                    if (bFixAspect && fAspectRatio > fNativeAspect)
                        ctx.xmm1.f32[0] = atanf(tanf(ctx.xmm1.f32[0] * (fPi / 360)) / fNativeAspect * fAspectRatio) * (360 / fPi);
                    
                    if (bGlobalFOVMulti)
                        ctx.xmm1.f32[0] *= fFOVMulti;
                });

            AspectRatioMidHook = safetyhook::create_mid(AspectRatioFOVScanResult + 0xB,
                [](SafetyHookContext& ctx) {
                    if (bFixAspect && !bMovieIsPlaying)
                        ctx.rax = *(uint32_t*)(&fAspectRatio);
                });
        }
        else {
            spdlog::error("Aspect Ratio/FOV: Pattern scan failed.");
        }
    }

    if (bFixAspect) {
        // Minecart Minigame
        std::uint8_t* MinecartMinigameScanResult = Memory::PatternScan(exeModule, "48 8B ?? ?? ?? ?? ?? C5 FA ?? ?? C5 FA ?? ?? ?? ?? ?? ?? C5 FA ?? ?? ?? ?? ?? ?? C5 F2 ?? ?? C5 F2 ?? ?? ?? ?? ?? ??");
        if (MinecartMinigameScanResult) {
            spdlog::info("Minecart Minigame: Address is {:s}+{:x}", sExeName.c_str(), MinecartMinigameScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid MinecartMinigameWidthMidHook{};
            MinecartMinigameWidthMidHook = safetyhook::create_mid(MinecartMinigameScanResult,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio > fNativeAspect) {
                        ctx.xmm4.f32[0] = iCurrentResY * fNativeAspect;
                        ctx.xmm0.f32[0] -= (iCurrentResX - ctx.xmm4.f32[0]) / 2.00f;
                    }
                });

            static SafetyHookMid MinecartMinigameHeightMidHook{};
            MinecartMinigameHeightMidHook = safetyhook::create_mid(MinecartMinigameScanResult + 0x1B,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio < fNativeAspect) {
                        ctx.xmm3.f32[0] = iCurrentResX / fNativeAspect;
                        ctx.xmm1.f32[0] -= (iCurrentResY - ctx.xmm3.f32[0]) / 2.00f;
                    }
                });
        }
        else {
            spdlog::error("Minecart Minigame: Pattern scan failed.");
        }
    }

    if (!bGlobalFOVMulti && fFOVMulti != 1.00f) {
        if (GameplayFOVScanResult && GameplayFOVAltScanResult) {
            spdlog::info("Gameplay FOV: Address is {:s}+{:x}", sExeName.c_str(), GameplayFOVScanResult - (std::uint8_t*)exeModule);

            GameplayFOVMidHook = safetyhook::create_mid(GameplayFOVScanResult,
                [](SafetyHookContext& ctx) {
                    if (ctx.r13) {                       
                        auto CamType = static_cast<SDK::EEndCameraOperatorType>(ctx.r13);
                        if (CamType == SDK::EEndCameraOperatorType::Field || CamType == SDK::EEndCameraOperatorType::Battle)
                            ctx.xmm0.f32[0] *= fFOVMulti;                  
                    }
                });

            spdlog::info("Gameplay FOV: Alt: Address is {:s}+{:x}", sExeName.c_str(), GameplayFOVAltScanResult - (std::uint8_t*)exeModule);
            GameplayFOVAltMidHook = safetyhook::create_mid(GameplayFOVAltScanResult,
                [](SafetyHookContext& ctx) {
                    if (ctx.r13) {
                        auto CamType = static_cast<SDK::EEndCameraOperatorType>(ctx.r13);
                        if (CamType == SDK::EEndCameraOperatorType::Field || CamType == SDK::EEndCameraOperatorType::Battle)
                            ctx.xmm0.f32[0] *= fFOVMulti;
                    }
                });
        }
        else {
            spdlog::error("Gameplay FOV: Pattern scan(s) failed.");
        }
    }
}

void HUD()
{
    if (bFixHUD) {
        // HUD Composite Layer
        std::uint8_t* HUDCompositeLayerScanResult = Memory::PatternScan(exeModule, "48 8B ?? ?? ?? ?? ?? 48 8D ?? ?? ?? ?? ?? C5 ?? ?? ?? ?? ?? ?? ?? 8B ?? ?? ?? ?? ?? 4C 8D ?? ?? 48 89 ?? ?? 41 ?? 01 00 00 00");
        if (HUDCompositeLayerScanResult) {
            spdlog::info("HUD: Composite Layer: Address is {:s}+{:x}", sExeName.c_str(), HUDCompositeLayerScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid HUDCompositeLayerMidHook{};
            HUDCompositeLayerMidHook = safetyhook::create_mid(HUDCompositeLayerScanResult,
                [](SafetyHookContext& ctx) {
                    if (ctx.rbx + 0x200 && !bMovieIsPlaying && fAspectRatio != fNativeAspect) {
                        // Calculate new HUD size if resolution changed
                        if (bHUDNeedsResize)
                            CalculateHUD(true); 

                        // Set render target dimensions. 
                        *reinterpret_cast<int*>(ctx.rbx + 0x200) = iCompositeLayerX;
                        *reinterpret_cast<int*>(ctx.rbx + 0x204) = iCompositeLayerY;
                    }
                });
        }
        else {
            spdlog::error("HUD: Composite Layer: Pattern scan failed.");
        }

        // Extra Composite Layer BG
        std::uint8_t* ExtraCompositeLayerBackgroundScanResult = Memory::PatternScan(exeModule, "4C 8D ?? ?? ?? ?? ?? BE 01 00 00 00 48 8D ?? ?? ?? 40 88 ?? ?? ?? 66 89 ?? ?? ?? C6 44 ?? ?? 00");
        if (ExtraCompositeLayerBackgroundScanResult) {
            spdlog::info("HUD: Extra Composite Layer: Background: Address is {:s}+{:x}", sExeName.c_str(), ExtraCompositeLayerBackgroundScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid ExtraCompositeLayerBackgroundMidHook{};
            ExtraCompositeLayerBackgroundMidHook = safetyhook::create_mid(ExtraCompositeLayerBackgroundScanResult,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio != fNativeAspect) {
                        // Set render target dimensions. 
                        ctx.rdx = (static_cast<uintptr_t>(iCompositeLayerY) << 32) | (static_cast<uintptr_t>(iCompositeLayerX) & 0xFFFFFFFF);
                    }
                });
        }
        else {
            spdlog::error("HUD: Extra Composite Layer: Background: Pattern scan failed.");
        }

        // Extra Composite Layer FG
        std::uint8_t* ExtraCompositeLayerForegroundScanResult = Memory::PatternScan(exeModule, "4C 8D ?? ?? ?? ?? ?? BE 01 00 00 00 48 8D ?? ?? ?? 40 88 ?? ?? ?? 66 89 ?? ?? ?? C6 44 ?? ?? 00");
        if (ExtraCompositeLayerForegroundScanResult) {
            spdlog::info("HUD: Extra Composite Layer: Foreground: Address is {:s}+{:x}", sExeName.c_str(), ExtraCompositeLayerForegroundScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid ExtraCompositeLayerForegroundMidHook{};
            ExtraCompositeLayerForegroundMidHook = safetyhook::create_mid(ExtraCompositeLayerForegroundScanResult,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio != fNativeAspect) {
                        // Set render target dimensions. 
                        ctx.rdx = (static_cast<uintptr_t>(iCompositeLayerY) << 32) | (static_cast<uintptr_t>(iCompositeLayerX) & 0xFFFFFFFF);
                    }
                });
        }
        else {
            spdlog::error("HUD: Extra Composite Layer: Foreground: Pattern scan failed.");
        }

        // Extra Composite Layer Rect
        std::uint8_t* ExtraCompositeLayerRectScanResult = Memory::PatternScan(exeModule, "C5 ?? ?? ?? ?? C7 ?? ?? 00 00 80 3F 48 ?? ?? ?? ?? ?? ?? 48 ?? ?? E8 ?? ?? ?? ??");
        if (ExtraCompositeLayerRectScanResult) {
            spdlog::info("HUD: Extra Composite Layer: Rect: Address is {:s}+{:x}", sExeName.c_str(), ExtraCompositeLayerRectScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid ExtraCompositeLayerRectMidHook{};
            ExtraCompositeLayerRectMidHook = safetyhook::create_mid(ExtraCompositeLayerRectScanResult + 0x5,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio != fNativeAspect) {
                        *reinterpret_cast<float*>(ctx.rcx + 0x10) = fHUDWidthOffset;                    // Left
                        *reinterpret_cast<float*>(ctx.rcx + 0x14) = fHUDHeightOffset;                   // Top
                        *reinterpret_cast<float*>(ctx.rcx + 0x1C) = fHUDWidth + fHUDWidthOffset;        // Right
                        *reinterpret_cast<float*>(ctx.rcx + 0x20) = fHUDHeight + fHUDHeightOffset;      // Bottom
                    }
                });
        }
        else {
            spdlog::error("HUD: Extra Composite Layer: Rect: Pattern scan failed.");
        }

        // HUD Size
        std::uint8_t* HUDSizeScanResult = Memory::PatternScan(exeModule, "C5 FA 11 ?? ?? ?? ?? ?? ?? C5 FA 11 ?? ?? ?? ?? ?? ?? C5 FA ?? ?? ?? ?? C5 FA ?? ?? ?? ?? C5 FA ?? ?? ?? ?? E8 ?? ?? ?? ??");
        if (HUDSizeScanResult) {
            spdlog::info("HUD: Size: Address is {:s}+{:x}", sExeName.c_str(), HUDSizeScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid HUDSizeMidHook{};
            HUDSizeMidHook = safetyhook::create_mid(HUDSizeScanResult,
                [](SafetyHookContext& ctx) {
                    if (!bMovieIsPlaying) {
                        if (fAspectRatio != fNativeAspect) {
                            *reinterpret_cast<float*>(ctx.rsp + 0x78) = fHUDScale;
                            *reinterpret_cast<float*>(ctx.rsp + 0x7C) = fHUDWidthOffset;
                            *reinterpret_cast<float*>(ctx.rsp + 0x80) = fHUDHeightOffset;
                        }
                    }
                });
        }
        else {
            spdlog::error("HUD: Size: Pattern scan failed.");
        }

        // Menu Highlights (Steam)
        std::uint8_t* SteamHUDMenuHighlightsScanResult = Memory::PatternScan(exeModule, "C5 FA ?? ?? ?? ?? C4 E2 ?? ?? ?? ?? ?? 8B ?? ?? ?? ?? ?? 48 8D ?? ?? C5 ?? ?? ?? C5 ?? ?? ?? C5 FA ?? ?? ?? ??");
        if (SteamHUDMenuHighlightsScanResult) {
            spdlog::info("HUD: Menu Highlights (Steam): Address is {:s}+{:x}", sExeName.c_str(), SteamHUDMenuHighlightsScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid SteamHUDMenuHighlightsWidthMidHook{};
            SteamHUDMenuHighlightsWidthMidHook = safetyhook::create_mid(SteamHUDMenuHighlightsScanResult,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio != fNativeAspect) {
                        ctx.xmm0.f32[0] -= fHUDWidthOffset;
                        ctx.xmm4.f32[0] = 1.00f / fHUDScale;
                    }
                });

            static SafetyHookMid SteamHUDMenuHighlightsHeightMidHook{};
            SteamHUDMenuHighlightsHeightMidHook = safetyhook::create_mid(SteamHUDMenuHighlightsScanResult + 0x25,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio != fNativeAspect) {
                        ctx.xmm0.f32[0] -= fHUDHeightOffset;
                    }
                });
        }
        else {
            spdlog::error("HUD: Menu Highlights (Steam): Pattern scan failed.");

            // Menu Highlights (Epic)
            std::uint8_t* EpicHUDMenuHighlightsScanResult = Memory::PatternScan(exeModule, "C5 FA ?? ?? ?? ?? C4 E2 ?? ?? ?? ?? ?? 8B ?? ?? ?? ?? ?? 48 8D ?? ?? C5 EA ?? ??");
            if (EpicHUDMenuHighlightsScanResult) {
                spdlog::info("HUD: Menu Highlights (Epic): Address is {:s}+{:x}", sExeName.c_str(), EpicHUDMenuHighlightsScanResult - (std::uint8_t*)exeModule);
                static SafetyHookMid EpicHUDMenuHighlightsWidthMidHook{};
                EpicHUDMenuHighlightsWidthMidHook = safetyhook::create_mid(EpicHUDMenuHighlightsScanResult,
                    [](SafetyHookContext& ctx) {
                        if (fAspectRatio != fNativeAspect) {
                            ctx.xmm0.f32[0] -= fHUDWidthOffset;
                            ctx.xmm5.f32[0] = 1.00f / fHUDScale;
                        }
                    });

                static SafetyHookMid EpicHUDMenuHighlightsHeightMidHook{};
                EpicHUDMenuHighlightsHeightMidHook = safetyhook::create_mid(EpicHUDMenuHighlightsScanResult + 0x21,
                    [](SafetyHookContext& ctx) {
                        if (fAspectRatio != fNativeAspect) {
                            ctx.xmm2.f32[0] -= fHUDHeightOffset;
                        }
                    });
            }
            else {
                spdlog::error("HUD: Menu Highlights (Epic): Pattern scan failed.");
            }
        }

        // Map
        std::uint8_t* HUDMapUpperScanResult = Memory::PatternScan(exeModule, "E8 ?? ?? ?? ?? C5 FA ?? ?? ?? ?? C5 FA ?? ?? 48 8B ?? ?? ?? ?? ?? C5 FA ?? ?? ?? C5 FA ?? ?? C5 FA ?? ?? ?? 68");
        std::uint8_t* HUDMapLowerScanResult = Memory::PatternScan(exeModule, "E8 ?? ?? ?? ?? C5 FA ?? ?? ?? C5 ?? ?? ?? 48 8B ?? ?? ?? ?? ?? C5 ?? ?? ?? C5 FA ?? ?? ?? ?? C5 FA ?? ?? ?? 48 8B ??");
        if (HUDMapUpperScanResult && HUDMapLowerScanResult) {
            spdlog::info("HUD: Map: Upper: Address is {:s}+{:x}", sExeName.c_str(), HUDMapUpperScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid HUDMapUpperMidHook{};
            HUDMapUpperMidHook = safetyhook::create_mid(HUDMapUpperScanResult + 0x5,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio != fNativeAspect) {
                        ctx.xmm0.f32[0] = fHUDScale;
                    }    
                });

            spdlog::info("HUD: Map: Lower: Address is {:s}+{:x}", sExeName.c_str(), HUDMapLowerScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid HUDMapLowerMidHook{};
            HUDMapLowerMidHook = safetyhook::create_mid(HUDMapLowerScanResult + 0x5,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio != fNativeAspect) {
                        ctx.xmm0.f32[0] = fHUDScale;
                    }
                });
        }
        else {
            spdlog::error("HUD: Map: Pattern scan(s) failed.");
        }

        // QTE Prompts
        // TODO: This still isn't right as they move up and down with the camera, but at least they're visible now.
        std::uint8_t* QTEPromptsScanResult = Memory::PatternScan(exeModule, "C5 C2 ?? ?? ?? ?? ?? ?? C5 FC ?? ?? ?? ?? ?? ?? ?? C5 FC ?? ?? ?? ?? ?? ?? C5 FC ?? ?? ?? ?? ?? ?? ??");
        if (QTEPromptsScanResult) {
            spdlog::info("HUD: QTE Prompts: Address is {:s}+{:x}", sExeName.c_str(), QTEPromptsScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid QTEPromptsOffsetMidHook{};
            QTEPromptsOffsetMidHook = safetyhook::create_mid(QTEPromptsScanResult,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio != fNativeAspect) {
                        ctx.xmm6.f32[0] += fHUDWidthOffset * 2.00f;
                        ctx.xmm7.f32[0] += fHUDHeightOffset * 2.00f;
                    }
                });

            static SafetyHookMid QTEPromptsScaleMidHook{};
            QTEPromptsScaleMidHook = safetyhook::create_mid(QTEPromptsScanResult + 0x52,
                [](SafetyHookContext& ctx) {
                    if (fAspectRatio > fNativeAspect)
                        *reinterpret_cast<float*>(ctx.rsp + 0x4C) = 0.20f / fHUDScale;
                    else if (fAspectRatio < fNativeAspect)
                        *reinterpret_cast<float*>(ctx.rsp + 0x50) = 0.20f / fHUDScale;
                });
        }
        else {
            spdlog::error("HUD: QTE Prompts: Pattern scan failed.");
        }

        // Fades
        std::uint8_t* HUDFadesScanResult = Memory::PatternScan(exeModule, "48 8B ?? ?? ?? ?? ?? ?? 48 89 ?? ?? ?? 48 8B ?? E8 ?? ?? ?? ?? 48 8B ?? ?? ?? 48 8B ?? ?? ?? 48 8B ?? ?? ??");
        if (HUDFadesScanResult) {
            spdlog::info("HUD: Fades: Address is {:s}+{:x}", sExeName.c_str(), HUDFadesScanResult - (std::uint8_t*)exeModule);
            std::uint8_t* HUDFadesFunc = Memory::GetAbsolute(HUDFadesScanResult + 0x11);
            spdlog::info("HUD: Fades: Function: Address is {:s}+{:x}", sExeName.c_str(), HUDFadesFunc - (std::uint8_t*)exeModule);

            static SafetyHookMid HUDFadesSizeMidHook{};
            HUDFadesSizeMidHook = safetyhook::create_mid(HUDFadesFunc + 0x1B9,
                [](SafetyHookContext& ctx) {
                    if (!bMovieIsPlaying) {
                        if (fAspectRatio > fNativeAspect) {
                            ctx.xmm0.f32[0] = (ctx.xmm0.f32[1] * fAspectRatio) + 64.00f;
                            ctx.xmm0.f32[1] += 64.00f;
                        }
                        else if (fAspectRatio < fNativeAspect) {
                            ctx.xmm0.f32[0] += 64.00f;
                            ctx.xmm0.f32[1] = (ctx.xmm0.f32[0] / fAspectRatio) + 64.00f;
                        }
                    }
                });

            static SafetyHookMid HUDFadesOffsetMidHook{};
            HUDFadesOffsetMidHook = safetyhook::create_mid(HUDFadesFunc + 0x1C8,
                [](SafetyHookContext& ctx) {
                    if (!bMovieIsPlaying) {
                        if (fAspectRatio > fNativeAspect)
                            ctx.xmm0.f32[0] = 0.00f;
                        else if (fAspectRatio < fNativeAspect)
                            ctx.xmm0.f32[1] = 0.00f;
                    }
                });
        }
        else {
            spdlog::error("HUD: Fades: Pattern scan failed.");
        }
    }

    if (bFixMovies) {
        // Movies
        std::uint8_t* ShowMovieScanResult = Memory::PatternScan(exeModule, "4C 8B ?? 48 8B ?? 48 8B ?? E8 ?? ?? ?? ?? 48 8B ?? ?? ?? 48 83 ?? ?? 5F C3 E8 ?? ?? ?? ?? EB ??");
        if (ShowMovieScanResult) {
            spdlog::info("HUD: Movie: Address is {:s}+{:x}", sExeName.c_str(), ShowMovieScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid ShowMovieMidHook{};
            ShowMovieMidHook = safetyhook::create_mid(Memory::GetAbsolute(ShowMovieScanResult + 0xA),
                [](SafetyHookContext& ctx) {
                    #ifdef _DEBUG
                    spdlog::info("EndMenu.ShowMovie()");
                    #endif
                    bMovieIsPlaying = true;
                });

            static SafetyHookMid HideMovieMidHook{};
            HideMovieMidHook = safetyhook::create_mid(Memory::GetAbsolute(ShowMovieScanResult + 0x1A),
                [](SafetyHookContext& ctx) {
                    #ifdef _DEBUG
                    spdlog::info("EndMenu.HideMovie()");
                    #endif
                    bMovieIsPlaying = false;
                });
        }
        else {
            spdlog::error("HUD: Movie: Pattern scan(s) failed.");
        }
    }

    // HUD Widgets
    std::uint8_t* HUDWidgetsScanResult = Memory::PatternScan(exeModule, "48 8D ?? ?? ?? ?? ?? 89 ?? ?? ?? 8B ?? ?? 89 ?? ?? ?? 49 ?? ?? 48 89 ?? ?? ?? E8 ?? ?? ?? ?? 48 8B ?? 48 85 ?? 74 ??");
    if (HUDWidgetsScanResult) {
        static SDK::UObject* obj = nullptr;
        static SDK::UObject* oldObj = nullptr;

        static std::string objName;
        static std::string objOldName;

        spdlog::info("HUD: Widgets: Address is {:s}+{:x}", sExeName.c_str(), HUDWidgetsScanResult - (std::uint8_t*)exeModule);
        static SafetyHookMid HUDWidgetsMidHook{};
        HUDWidgetsMidHook = safetyhook::create_mid(Memory::GetAbsolute(HUDWidgetsScanResult + 0x3),
            [](SafetyHookContext& ctx) {
                obj = (SDK::UObject*)ctx.rcx;

                // Check if object has changed
                if (obj != oldObj) {
                    oldObj = obj;

                    // Only store the name of the object when it has changed
                    objName = obj->GetName();

                    // "Pause_00_C", "simple" pause menu
                    if (objName.contains("Pause_00_C") && UMGPauseMenu != obj) {
                        #ifdef _DEBUG
                        spdlog::info("HUD: Widgets: Pause Menu: {}", objName);
                        spdlog::info("HUD: Widgets: Pause Menu: Address: {:x}", (uintptr_t)obj);
                        #endif

                        // Cache address
                        UMGPauseMenu = (SDK::UPause_00_C*)obj;

                        // // Get root widget and panel slot(s)
                        SDK::UEndCanvasPanel* rootWidget = (SDK::UEndCanvasPanel*)UMGPauseMenu->WidgetTree->RootWidget;
                        SDK::UEndCanvasPanelSlot* bgSlot = (SDK::UEndCanvasPanelSlot*)rootWidget->Slots[0];
                        SDK::UEndCanvasPanelSlot* gradientSlot = (SDK::UEndCanvasPanelSlot*)rootWidget->Slots[1];

                        // Create offsets
                        SDK::FMargin offsets = SDK::FMargin(0.00f, 0.00f, 1920.00f, 1080.00f);

                        // Adjust offsets to allow backgrounds to fill the screen
                        if (fAspectRatio > fNativeAspect)
                            offsets.RIGHT = 1080.00f * fAspectRatio;
                        else if (fAspectRatio < fNativeAspect)
                            offsets.Bottom = 1920.00f / fAspectRatio;

                        // Set adjusted offsets
                        bgSlot->SetOffsets(offsets);
                        gradientSlot->SetOffsets(offsets);
                    }

                    // "Com_Window_01_C", menu dialog window
                    if (objName.contains("Com_Window_01_C") && UMGComWindow != obj) {
                        #ifdef _DEBUG
                        spdlog::info("HUD: Widgets: Com Window: {}", objName);
                        spdlog::info("HUD: Widgets: Com Window: Address: {:x}", (uintptr_t)obj);
                        #endif

                        // Cache address
                        UMGComWindow = (SDK::UCom_Window_01_C*)obj;

                        // Adjust to span the screen
                        if (fAspectRatio > fNativeAspect) {
                            *reinterpret_cast<float*>(ctx.rcx + 0x210) = -(fHUDWidthOffset / fHUDWidth);
                            *reinterpret_cast<float*>(ctx.rcx + 0x214) = 0.00f;
                            *reinterpret_cast<float*>(ctx.rcx + 0x218) = 1.00f + (fHUDWidthOffset / fHUDWidth);
                            *reinterpret_cast<float*>(ctx.rcx + 0x21C) = 1.00f;
                        }
                        else if (fAspectRatio < fNativeAspect) {
                            *reinterpret_cast<float*>(ctx.rcx + 0x210) = 0.00f;
                            *reinterpret_cast<float*>(ctx.rcx + 0x214) = -(fHUDHeightOffset / fHUDHeight);
                            *reinterpret_cast<float*>(ctx.rcx + 0x218) = 1.00f;
                            *reinterpret_cast<float*>(ctx.rcx + 0x21C) = 1.00f + (fHUDHeightOffset / fHUDHeight);
                        }
                    }

                    // "AreaMap_TopBase_C", area map (a.k.a the thing that comes up when you press tab) base layer
                    if (objName.contains("AreaMap_TopBase_C") && UMGAreaMap != obj) {
                        #ifdef _DEBUG
                        spdlog::info("HUD: Widgets: Area Map Top Base: {}", objName);
                        spdlog::info("HUD: Widgets: Area Map Top Base: Address: {:x}", (uintptr_t)obj);
                        #endif

                        // Cache address
                        UMGAreaMap = (SDK::UAreaMap_TopBase_C*)obj;

                        // Adjust to span the screen
                        if (fAspectRatio > fNativeAspect) {
                            *reinterpret_cast<float*>(ctx.rcx + 0x210) = -(fHUDWidthOffset / fHUDWidth);
                            *reinterpret_cast<float*>(ctx.rcx + 0x214) = 0.00f;
                            *reinterpret_cast<float*>(ctx.rcx + 0x218) = 1.00f + (fHUDWidthOffset / fHUDWidth);
                            *reinterpret_cast<float*>(ctx.rcx + 0x21C) = 1.00f;
                        }
                        else if (fAspectRatio < fNativeAspect) {
                            *reinterpret_cast<float*>(ctx.rcx + 0x210) = 0.00f;
                            *reinterpret_cast<float*>(ctx.rcx + 0x214) = -(fHUDHeightOffset / fHUDHeight);
                            *reinterpret_cast<float*>(ctx.rcx + 0x218) = 1.00f;
                            *reinterpret_cast<float*>(ctx.rcx + 0x21C) = 1.00f + (fHUDHeightOffset / fHUDHeight);
                        }
                    }

                    // "VR_Top_C", Chadley combat simulator menu
                    if (objName.contains("VR_Top_C") && UMGVRTop != obj) {
                        #ifdef _DEBUG
                        spdlog::info("HUD: Widgets: VR Top: {}", objName);
                        spdlog::info("HUD: Widgets: VR Top: Address: {:x}", (uintptr_t)obj);
                        #endif

                        // Cache address
                        UMGVRTop = (SDK::UVR_Top_C*)obj;

                        // Adjust to span the screen
                        if (fAspectRatio > fNativeAspect) {
                            *reinterpret_cast<float*>(ctx.rcx + 0x210) = -(fHUDWidthOffset / fHUDWidth);
                            *reinterpret_cast<float*>(ctx.rcx + 0x214) = 0.00f;
                            *reinterpret_cast<float*>(ctx.rcx + 0x218) = 1.00f + (fHUDWidthOffset / fHUDWidth);
                            *reinterpret_cast<float*>(ctx.rcx + 0x21C) = 1.00f;
                        }
                        else if (fAspectRatio < fNativeAspect) {
                            *reinterpret_cast<float*>(ctx.rcx + 0x210) = 0.00f;
                            *reinterpret_cast<float*>(ctx.rcx + 0x214) = -(fHUDHeightOffset / fHUDHeight);
                            *reinterpret_cast<float*>(ctx.rcx + 0x218) = 1.00f;
                            *reinterpret_cast<float*>(ctx.rcx + 0x21C) = 1.00f + (fHUDHeightOffset / fHUDHeight);
                        }
                    }

                    // "BattleTips_C", tutorial windows
                    if (objName.contains("BattleTips_C") && UMGBattleTips != obj) {
                        #ifdef _DEBUG
                        spdlog::info("HUD: Widgets: Battle Tips: {}", objName);
                        spdlog::info("HUD: Widgets: Battle Tips: Address: {:x}", (uintptr_t)obj);
                        #endif

                        // Cache address
                        UMGBattleTips = (SDK::UBattleTips_C*)obj;

                        // Adjust background to span the screen
                        if (UMGBattleTips->Img_BlackFilter) {
                            if (fAspectRatio > fNativeAspect)
                                UMGBattleTips->Img_BlackFilter->SetRenderScale(SDK::FVector2D(fAspectMultiplier, 1.00f));
                            else if (fAspectRatio < fNativeAspect)
                                UMGBattleTips->Img_BlackFilter->SetRenderScale(SDK::FVector2D(1.00f, 1.00f / fAspectMultiplier));
                        }
                    }

                    // "MainMenu_Top_Window_C", Main Menu
                    if (objName.contains("MainMenu_Top_Window_C") && UMGMainMenu != obj) {
                        #ifdef _DEBUG
                        spdlog::info("HUD: Widgets: Main Menu: {}", objName);
                        spdlog::info("HUD: Widgets: Main Menu: Address: {:x}", (uintptr_t)obj);
                        #endif

                        // Cache address
                        UMGMainMenu = (SDK::UMainMenu_Top_Window_C*)obj;

                        // Adjust left menu gradient
                        if (fAspectRatio > fNativeAspect) {
                            auto* panel = UMGMainMenu->TopContent2->EndCanvasPanel_0;
                            if (panel->Slots.IsValidIndex(0)) {
                                auto* leftMenuGradient = (SDK::UEndCanvasPanelSlot*)panel->Slots[0];
                                auto offsets = leftMenuGradient->GetOffsets();
                                offsets.LEFT = -10.00f - (((1080.00f * fAspectRatio) - 1920.00f) / 2.00f);
                                leftMenuGradient->SetOffsets(offsets);
                            }
                        }
                    }
                }
            });
    }
    else {
        spdlog::error("HUD: Widgets: Pattern scan failed.");
    }
}

void Graphics()
{
    if (bFixAspect) {
        // White screen bug with post-processing
        std::uint8_t* WhiteScreenBugScanResult = Memory::PatternScan(exeModule, "41 ?? ?? ?? ?? ?? ?? 00 C7 ?? ?? 80 07 00 00 C7 ?? ?? 38 04 00 00 48 ?? ?? ?? ?? ?? ??");
        if (WhiteScreenBugScanResult) {
            spdlog::info("White Screen Bug: Address is {:s}+{:x}", sExeName.c_str(), WhiteScreenBugScanResult - (std::uint8_t*)exeModule);
            Memory::PatchBytes(WhiteScreenBugScanResult + 0xB, "\x81", 1);
            spdlog::info("White Screen Bug: Patched instruction.");
        }
        else {
            spdlog::error("White Screen Bug: Pattern scan failed.");
        }
    }

    if (bAutoVignette || fVignetteStrength != 1.00f) {
        // Post Processing 
        std::uint8_t* PostProcessingScanResult = Memory::PatternScan(exeModule, "80 ?? ?? FE C5 ?? ?? 48 8B ?? ?? ?? 48 8B ?? ?? ?? 48 8B ?? ?? ?? C5 ?? ?? ?? ?? ?? 48 83 ?? ??");
        if (PostProcessingScanResult) {
            spdlog::info("Post Processing: Address is {:s}+{:x}", sExeName.c_str(), PostProcessingScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid PostProcessingMidHook{};
            PostProcessingMidHook = safetyhook::create_mid(PostProcessingScanResult,
                [](SafetyHookContext& ctx) {
                    SDK::FPostProcessSettings* PP = (SDK::FPostProcessSettings*)ctx.rbx;

                    if (!bAutoVignette && fVignetteStrength != 1.00f)
                        PP->LensVignetteIntensity = fVignetteStrength;
                    else if (bAutoVignette && fAspectRatio > fNativeAspect)
                        PP->LensVignetteIntensity = 1.00f / fAspectMultiplier;
                });
        }
        else {
            spdlog::error("Post Processing: Pattern scan failed.");
        }
    }

    if (iShadowResolution != 2048 || bShadowDistTweak) {
        // Cascaded shadow map settings
        std::uint8_t* ShadowCascadeSettingsScanResult = Memory::PatternScan(exeModule, "85 ?? 41 0F ?? ?? 89 ?? ?? ?? ?? ?? 8B ?? ?? ?? ?? ?? 89 ?? ?? ?? ?? ??");
        if (ShadowCascadeSettingsScanResult) {
            spdlog::info("Shadow Cascade Settings: Address is {:s}+{:x}", sExeName.c_str(), ShadowCascadeSettingsScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid SplitNearMidHook{};
            SplitNearMidHook = safetyhook::create_mid(ShadowCascadeSettingsScanResult + 0x1E,
                [](SafetyHookContext& ctx) {
                    if (iShadowResolution != 2048 && SDK::UWorld::GetWorld()) {
                        // Set shadow resolution
                        std::wstring csmResCvar = L"r.Shadow.MaxCSMResolution " + std::to_wstring(iShadowResolution);
                        SDK::UKismetSystemLibrary::ExecuteConsoleCommand(SDK::UWorld::GetWorld(), csmResCvar.c_str(), nullptr);
                    }

                    if (bShadowDistTweak) {
                        // Adjust near split
                        float splitNear = *reinterpret_cast<float*>(&ctx.rax);

                        // If near split distance is 500, change it to 1500
                        if (splitNear >= 499.00f && splitNear <= 501.00f) {
                            splitNear = 1500.00f;
                            ctx.rax = *reinterpret_cast<uintptr_t*>(&splitNear);
                        }
                    }
                });

            static SafetyHookMid SplitMidMidHook{};
            SplitMidMidHook = safetyhook::create_mid(ShadowCascadeSettingsScanResult + 0x2A,
                [](SafetyHookContext& ctx) {
                    if (bShadowDistTweak) {
                        // Adjust mid split
                        float splitMid = *reinterpret_cast<float*>(&ctx.rax);

                        // If mid split distance is 5000, change it to 7000
                        if (splitMid >= 4999.00f && splitMid <= 5001.00f) {
                            splitMid = 7000.00f;
                            ctx.rax = *reinterpret_cast<uintptr_t*>(&splitMid);
                        }
                    }
                });
        }
        else {
            spdlog::error("Shadow Cascade Settings: Pattern scan failed.");
        }
    }
}

void Misc()
{
    if (fFramerateLimit != 120.00f) {
        // Replace 120 fps option with desired framerate limit
        std::uint8_t* FramerateLimitScanResult = Memory::PatternScan(exeModule, "B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 ?? ?? 48 8B ?? 48 8D ?? ?? ?? ?? ?? C5 F2 ?? ??");
        std::uint8_t* FramerateLimitStringScanResult = Memory::PatternScan(exeModule, "24 00 6D 00 65 00 6E 00 75 00 5F 00 6F 00 70 00 74 00 69 00 6F 00 6E 00 73 00 5F 00 66 00 70 00 73 00 5F 00 31 00 32 00 30");
        if (FramerateLimitScanResult && FramerateLimitStringScanResult) {
            spdlog::info("Framerate Limit: Address is {:s}+{:x}", sExeName.c_str(), FramerateLimitScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid FramerateLimitMidHook{};
            FramerateLimitMidHook = safetyhook::create_mid(FramerateLimitScanResult,
                [](SafetyHookContext& ctx) {
                    // 120 fps option
                    if (ctx.xmm6.f32[0] >= 119.00f && ctx.xmm6.f32[0] <= 121.00f) {
                        ctx.xmm1.f32[0] = fFramerateLimit;
                        #ifdef _DEBUG
                        spdlog::info("Framerate Limit: Set 120 fps option to {:.4f} fps", fFramerateLimit);
                        #endif
                    }
                });

            // Write new string for the 120fps option ($menu_options_fps_120)
            const wchar_t* fpsString = L"$menu_options_fps_120";

            DWORD oldProtect;
            if (VirtualProtect(FramerateLimitStringScanResult, (std::wcslen(fpsString) + 1) * sizeof(wchar_t), PAGE_EXECUTE_READWRITE, &oldProtect)) {
                std::swprintf(reinterpret_cast<wchar_t*>(FramerateLimitStringScanResult), 41, L"%.0f fps", fFramerateLimit);
                VirtualProtect(FramerateLimitStringScanResult, (std::wcslen(fpsString) + 1) * sizeof(wchar_t), oldProtect, &oldProtect);
            }   
        }
        else {
            spdlog::error("Framerate Limit: Pattern scan(s) failed.");
        }
    }

    if (fSubtitleScale != 1.00f) {
        // Subtitles
        std::uint8_t* ShowSubtitlesScanResult = Memory::PatternScan(exeModule, "48 8B ?? 48 85 ?? 0F 84 ?? ?? ?? ?? 0F ?? ?? ?? ?? EB ?? 45 33 ?? 44 39 ?? ?? ?? ?? ?? B2 03");
        if (ShowSubtitlesScanResult) {
            spdlog::info("Subtitles: Address is {:s}+{:x}", sExeName.c_str(), ShowSubtitlesScanResult - (std::uint8_t*)exeModule);
            static SafetyHookMid ShowSubtitlesMidHook{};
            ShowSubtitlesMidHook = safetyhook::create_mid(ShowSubtitlesScanResult,
                [](SafetyHookContext& ctx) {
                    if (ctx.rax) {
                        SDK::UObject* obj = (SDK::UObject*)ctx.rax;

                        if (UMGSubtitles != obj) {
                            // Cache object
                            UMGSubtitles = (SDK::USubtitle00_C*)obj;

                            #ifdef _DEBUG
                            spdlog::info("Subtitles: Widget: {}", obj->GetFullName());
                            spdlog::info("Subtitles: Widgets Address: {:x}", (uintptr_t)obj);
                            #endif

                            // Apply size scale to subtitles
                            if (UMGSubtitles->Txt_Lines)
                                UMGSubtitles->Txt_Lines->GetParent()->SetRenderScale(SDK::FVector2D(fSubtitleScale, fSubtitleScale));
                        }
                    }
                });
        }
        else {
            spdlog::error("Subtitles: Pattern scan failed.");
        }
    }

    // Increase camera distance limits
    std::uint8_t* OptionsMenuScanResult = Memory::PatternScan(exeModule, "49 ?? ?? EB ?? 48 8B ?? 48 8D ?? ?? 48 ?? ?? 48 ?? ?? 48 ?? ?? 0F 84 ?? ?? ?? ?? 85 ?? 0F 88 ?? ?? ?? ??");
    if (OptionsMenuScanResult) {
        spdlog::info("Options Menu: Address is {:s}+{:x}", sExeName.c_str(), OptionsMenuScanResult - (std::uint8_t*)exeModule);
        static SafetyHookMid OptionsMenuMidHook{};
        OptionsMenuMidHook = safetyhook::create_mid(OptionsMenuScanResult,
            [](SafetyHookContext& ctx) {
                if (ctx.rsi) {
                    SDK::UObject* obj = (SDK::UObject*)ctx.rsi;

                    if (obj->IsA(SDK::UEndNewOptionsMenu::StaticClass())) {
                        auto optionsMenu = (SDK::UEndNewOptionsMenu*)obj;
                        auto options = optionsMenu->_OptionItems;

                        // Iterate over options
                        for (UC::TPair<SDK::EMenuItemCategory, SDK::FOptionInfos>& option : options) {
                            // Find camera options
                            if (option.Key() == SDK::EMenuItemCategory::CameraController) {
                                // Get option infos
                                auto& optionInfos = option.Value().Infos;
                                // Check if options are valid
                                if (optionInfos.IsValidIndex(0) && optionInfos.IsValidIndex(1)) {
                                    // Check if max value is unmodified
                                    if (optionInfos[0].RangeInfo.MaxValue == 3) {
                                        // Index 0 is Camera Distance: Out of Battle
                                        optionInfos[0].RangeInfo.MaxValue = 10;
                                        // Index 1 is Camera Distance: In Battle
                                        optionInfos[1].RangeInfo.MaxValue = 10;
                                    }
                                }
                            }
                        }
                    } 
                }
            });
    }
    else {
        spdlog::error("Options Menu: Pattern scan failed.");
    }

    /*
    static bool bHasSkippedIntro = false;

    // Title menu
    std::uint8_t* TitleMenuScanResult = Memory::PatternScan(exeModule, "48 89 ?? ?? ?? 57 B8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 ?? ?? 48 8B ?? E8 ?? ?? ?? ?? 48 8D ?? ?? ?? ?? ?? 48 8B ?? E8 ?? ?? ?? ?? 48 8B ?? 48 85 ?? 0F 84 ?? ?? ?? ?? 48 8B ?? E8 ?? ?? ?? ?? 84 ??  0F 84 ?? ?? ?? ?? B2 01 48 8B ?? E8 ?? ?? ?? ?? BA 01 00 00 00 E8 ?? ?? ?? ?? E8 ?? ?? ?? ?? 41 ?? 03");
    if (TitleMenuScanResult) {
        spdlog::info("Title Menu: Address is {:s}+{:x}", sExeName.c_str(), TitleMenuScanResult - (std::uint8_t*)exeModule);
        static SafetyHookMid TitleMenuMidHook{};
        TitleMenuMidHook = safetyhook::create_mid(TitleMenuScanResult,
            [](SafetyHookContext& ctx) {
                if (!bHasSkippedIntro) {
                    SDK::UEndTitleMenu* menu = (SDK::UEndTitleMenu*)ctx.rcx;
                    menu->OnPressedAnyButton();
                    #ifdef _DEBUG
                    spdlog::info("Title Menu: {:x} | {}", (uintptr_t)menu, menu->GetFullName());
                    #endif
                }
            });
    }
    else {
        spdlog::error("Title Menu: Pattern scan failed.");
    }

    // Start menu 
    std::uint8_t* StartMenuScanResult = Memory::PatternScan(exeModule, "8B ?? ?? ?? ?? ?? 48 8D ?? ?? ?? ?? ?? 48 8B ?? 83 ?? 05 0F 85 ?? ?? ?? ?? E8 ?? ?? ?? ??");
    if (StartMenuScanResult) {
        spdlog::info("Start Menu: Address is {:s}+{:x}", sExeName.c_str(), StartMenuScanResult - (std::uint8_t*)exeModule);
        static SafetyHookMid StartMenuMidHook{};
        StartMenuMidHook = safetyhook::create_mid((std::uint8_t*)StartMenuScanResult,
            [](SafetyHookContext& ctx) {
                if (!bHasSkippedIntro) {
                    SDK::UEndStartMenu* menu = (SDK::UEndStartMenu*)ctx.rdi;
                    //menu->OnLoadLatest();
                    bHasSkippedIntro = true;
                    SDK::UGameplayStatics::LoadGameFromSlot(L"0", 0);
                    #ifdef _DEBUG
                    spdlog::info("Start Menu: {:x} | {}", (uintptr_t)menu, menu->GetFullName());
                    #endif
                }
            });
    }
    else {
        spdlog::error("Start Menu: Pattern scan failed.");
    }
    */
}

// Low-level keyboard hook procedure
LRESULT CALLBACK LowLevelKeyboardProc( int nCode, WPARAM wParam, LPARAM lParam )
{
    if (nCode == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN))
    {
        KBDLLHOOKSTRUCT* pKey = (KBDLLHOOKSTRUCT*)lParam;
        DWORD vk = pKey->vkCode;

        if (vk == VK_MULTIPLY)
        {
            if (!(pKey->flags & KF_REPEAT))
            {
                bGlobalFOVMulti = !bGlobalFOVMulti;

				if (bGlobalFOVMulti)
					spdlog::info( "Global FOV multiplier enabled" );
				else
					spdlog::info( "Global FOV multiplier disabled" );
            }
        }

        if (vk >= VK_NUMPAD1 && vk <= VK_NUMPAD9)
        {
            // Check if the key was previously up (not a repeat)
            if (!(pKey->flags & KF_REPEAT))
            {
                int keyIndex = vk - VK_NUMPAD1;
                fFOVMulti = 0.6f + (keyIndex) * 0.1f;

				spdlog::info( "FOV multiplier set to {:.1f}", fFOVMulti );
			}
        }

        // This list of keys needs to change depending on whatever keys are used to change fov or toggle global fov multiplier (or other features)
        if ((vk >= VK_NUMPAD1 && vk <= VK_NUMPAD9) ||
            vk == VK_MULTIPLY)
        {
            if (!(pKey->flags & KF_REPEAT))
            {
                FOVMidHook.reset();
                AspectRatioMidHook.reset();
                GameplayFOVMidHook.reset();
                GameplayFOVAltMidHook.reset();

                if (bFixAspect || bGlobalFOVMulti)
                {
                    if (AspectRatioFOVScanResult)
                    {
                        FOVMidHook = safetyhook::create_mid( AspectRatioFOVScanResult,
                            []( SafetyHookContext& ctx ) {
                            // Fix vert- FOV when wider than 16:9
                            if (bFixAspect && fAspectRatio > fNativeAspect)
                                ctx.xmm1.f32[0] = atanf( tanf( ctx.xmm1.f32[0] * (fPi / 360) ) / fNativeAspect * fAspectRatio ) * (360 / fPi);

                            if (bGlobalFOVMulti)
                                ctx.xmm1.f32[0] *= fFOVMulti;
                        } );

                        AspectRatioMidHook = safetyhook::create_mid( AspectRatioFOVScanResult + 0xB,
                            []( SafetyHookContext& ctx ) {
                            if (bFixAspect && !bMovieIsPlaying)
                                ctx.rax = *(uint32_t*)(&fAspectRatio);
                        } );
                    }
                    else
                    {
                        spdlog::error( "Aspect Ratio/FOV: Pattern invalid so no FOV changes made." );
                    }
                }

                if (!bGlobalFOVMulti && fFOVMulti != 1.00f)
                {
                    if (GameplayFOVScanResult && GameplayFOVAltScanResult)
                    {
                        GameplayFOVMidHook = safetyhook::create_mid( GameplayFOVScanResult,
                            []( SafetyHookContext& ctx ) {
                            if (ctx.r13)
                            {
                                auto CamType = static_cast<SDK::EEndCameraOperatorType>(ctx.r13);
                                if (CamType == SDK::EEndCameraOperatorType::Field || CamType == SDK::EEndCameraOperatorType::Battle)
                                    ctx.xmm0.f32[0] *= fFOVMulti;
                            }
                        } );

                        GameplayFOVAltMidHook = safetyhook::create_mid( GameplayFOVAltScanResult,
                            []( SafetyHookContext& ctx ) {
                            if (ctx.r13)
                            {
                                auto CamType = static_cast<SDK::EEndCameraOperatorType>(ctx.r13);
                                if (CamType == SDK::EEndCameraOperatorType::Field || CamType == SDK::EEndCameraOperatorType::Battle)
                                    ctx.xmm0.f32[0] *= fFOVMulti;
                            }
                        } );
                    }
                    else
                    {
                        spdlog::error( "Gameplay FOV: Pattern(s) invalid so no FOV changes made." );
                    }
                }
            }
        }
    }
    return CallNextHookEx( nullptr, nCode, wParam, lParam );
}

void FOVChanger()
{
    
    if (!bDynamicFOVChanger)
    {
		spdlog::info( "Dynamic FOV Changer: Disabled" );
		return;
    }

    HHOOK hHook = SetWindowsHookEx( WH_KEYBOARD_LL, LowLevelKeyboardProc, thisModule, 0 );
    if (!hHook)
    {
        spdlog::error( "Failed to install keyboard hook: {}", GetLastError() );
        return;
    }

    MSG msg;
    while (GetMessage( &msg, nullptr, 0, 0 ) > 0)
    {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }

    UnhookWindowsHookEx( hHook );
}

DWORD __stdcall Main(void*)
{
    Logging();
    Configuration();
    UpdateOffsets();
    CurrentResolution();
    AspectRatioFOV();
    HUD();
    Graphics();
    Misc();
    FOVChanger();

    return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        thisModule = hModule;

        HANDLE mainHandle = CreateThread(NULL, 0, Main, 0, NULL, 0);
        if (mainHandle) {
            SetThreadPriority(mainHandle, THREAD_PRIORITY_HIGHEST);
            CloseHandle(mainHandle);
        }
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
