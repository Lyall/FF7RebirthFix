#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Quest_ProgressNow_Light

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass Quest_ProgressNow_Light.Quest_ProgressNow_Light_C
// 0x0028 (0x03F0 - 0x03C8)
class UQuest_ProgressNow_Light_C final : public UEndUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x03C8(0x0008)(ZeroConstructor, Transient, DuplicateTransient, UObjectWrapper)
	class UWidgetAnimation*                       Loop_PlayerLoca;                                   // 0x03D0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UEndImage*                              Img_Effect_00;                                     // 0x03D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_Effect_01;                                     // 0x03E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_Effect_02;                                     // 0x03E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_Quest_ProgressNow_Light(int32 EntryPoint);
	void Construct();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Quest_ProgressNow_Light_C">();
	}
	static class UQuest_ProgressNow_Light_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UQuest_ProgressNow_Light_C>();
	}
};
static_assert(alignof(UQuest_ProgressNow_Light_C) == 0x000008, "Wrong alignment on UQuest_ProgressNow_Light_C");
static_assert(sizeof(UQuest_ProgressNow_Light_C) == 0x0003F0, "Wrong size on UQuest_ProgressNow_Light_C");
static_assert(offsetof(UQuest_ProgressNow_Light_C, UberGraphFrame) == 0x0003C8, "Member 'UQuest_ProgressNow_Light_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UQuest_ProgressNow_Light_C, Loop_PlayerLoca) == 0x0003D0, "Member 'UQuest_ProgressNow_Light_C::Loop_PlayerLoca' has a wrong offset!");
static_assert(offsetof(UQuest_ProgressNow_Light_C, Img_Effect_00) == 0x0003D8, "Member 'UQuest_ProgressNow_Light_C::Img_Effect_00' has a wrong offset!");
static_assert(offsetof(UQuest_ProgressNow_Light_C, Img_Effect_01) == 0x0003E0, "Member 'UQuest_ProgressNow_Light_C::Img_Effect_01' has a wrong offset!");
static_assert(offsetof(UQuest_ProgressNow_Light_C, Img_Effect_02) == 0x0003E8, "Member 'UQuest_ProgressNow_Light_C::Img_Effect_02' has a wrong offset!");

}

