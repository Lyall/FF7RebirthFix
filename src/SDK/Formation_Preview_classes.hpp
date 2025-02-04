#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Formation_Preview

#include "Basic.hpp"

#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass Formation_Preview.Formation_Preview_C
// 0x00B0 (0x0478 - 0x03C8)
class UFormation_Preview_C final : public UEndUserWidget
{
public:
	class UWidgetAnimation*                       Decide;                                            // 0x03C8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       NoPreview;                                         // 0x03D0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Bahamut;                                           // 0x03D8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Ramuh;                                             // 0x03E0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Shiva;                                             // 0x03E8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Ifrit;                                             // 0x03F0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Hover;                                             // 0x03F8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Standard;                                          // 0x0400(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UEndImage*                              Bg;                                                // 0x0408(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Bg_6;                                              // 0x0410(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              BLACK;                                             // 0x0418(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UFormation_Cursor_C*                    Formation_Cursor;                                  // 0x0420(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImageSet*                           FormImageSet;                                      // 0x0428(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndBillboard*                          FormMovie;                                         // 0x0430(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Frame;                                             // 0x0438(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Frame_Cursor;                                      // 0x0440(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              InfoBg;                                            // 0x0448(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Light;                                             // 0x0450(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Light2;                                            // 0x0458(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Logo;                                              // 0x0460(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              TitleBg;                                           // 0x0468(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              TitleBg_Shadow;                                    // 0x0470(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Formation_Preview_C">();
	}
	static class UFormation_Preview_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UFormation_Preview_C>();
	}
};
static_assert(alignof(UFormation_Preview_C) == 0x000008, "Wrong alignment on UFormation_Preview_C");
static_assert(sizeof(UFormation_Preview_C) == 0x000478, "Wrong size on UFormation_Preview_C");
static_assert(offsetof(UFormation_Preview_C, Decide) == 0x0003C8, "Member 'UFormation_Preview_C::Decide' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, NoPreview) == 0x0003D0, "Member 'UFormation_Preview_C::NoPreview' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Bahamut) == 0x0003D8, "Member 'UFormation_Preview_C::Bahamut' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Ramuh) == 0x0003E0, "Member 'UFormation_Preview_C::Ramuh' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Shiva) == 0x0003E8, "Member 'UFormation_Preview_C::Shiva' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Ifrit) == 0x0003F0, "Member 'UFormation_Preview_C::Ifrit' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Hover) == 0x0003F8, "Member 'UFormation_Preview_C::Hover' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Standard) == 0x000400, "Member 'UFormation_Preview_C::Standard' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Bg) == 0x000408, "Member 'UFormation_Preview_C::Bg' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Bg_6) == 0x000410, "Member 'UFormation_Preview_C::Bg_6' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, BLACK) == 0x000418, "Member 'UFormation_Preview_C::BLACK' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Formation_Cursor) == 0x000420, "Member 'UFormation_Preview_C::Formation_Cursor' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, FormImageSet) == 0x000428, "Member 'UFormation_Preview_C::FormImageSet' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, FormMovie) == 0x000430, "Member 'UFormation_Preview_C::FormMovie' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Frame) == 0x000438, "Member 'UFormation_Preview_C::Frame' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Frame_Cursor) == 0x000440, "Member 'UFormation_Preview_C::Frame_Cursor' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, InfoBg) == 0x000448, "Member 'UFormation_Preview_C::InfoBg' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Light) == 0x000450, "Member 'UFormation_Preview_C::Light' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Light2) == 0x000458, "Member 'UFormation_Preview_C::Light2' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, Logo) == 0x000460, "Member 'UFormation_Preview_C::Logo' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, TitleBg) == 0x000468, "Member 'UFormation_Preview_C::TitleBg' has a wrong offset!");
static_assert(offsetof(UFormation_Preview_C, TitleBg_Shadow) == 0x000470, "Member 'UFormation_Preview_C::TitleBg_Shadow' has a wrong offset!");

}

