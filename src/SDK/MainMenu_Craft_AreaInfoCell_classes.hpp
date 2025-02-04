#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MainMenu_Craft_AreaInfoCell

#include "Basic.hpp"

#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass MainMenu_Craft_AreaInfoCell.MainMenu_Craft_AreaInfoCell_C
// 0x0020 (0x0400 - 0x03E0)
class UMainMenu_Craft_AreaInfoCell_C final : public UEndCraftAreaInfoCell
{
public:
	class UWidgetAnimation*                       On;                                                // 0x03E0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Off;                                               // 0x03E8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UEndImage*                              Base;                                              // 0x03F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Frame;                                             // 0x03F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MainMenu_Craft_AreaInfoCell_C">();
	}
	static class UMainMenu_Craft_AreaInfoCell_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMainMenu_Craft_AreaInfoCell_C>();
	}
};
static_assert(alignof(UMainMenu_Craft_AreaInfoCell_C) == 0x000008, "Wrong alignment on UMainMenu_Craft_AreaInfoCell_C");
static_assert(sizeof(UMainMenu_Craft_AreaInfoCell_C) == 0x000400, "Wrong size on UMainMenu_Craft_AreaInfoCell_C");
static_assert(offsetof(UMainMenu_Craft_AreaInfoCell_C, On) == 0x0003E0, "Member 'UMainMenu_Craft_AreaInfoCell_C::On' has a wrong offset!");
static_assert(offsetof(UMainMenu_Craft_AreaInfoCell_C, Off) == 0x0003E8, "Member 'UMainMenu_Craft_AreaInfoCell_C::Off' has a wrong offset!");
static_assert(offsetof(UMainMenu_Craft_AreaInfoCell_C, Base) == 0x0003F0, "Member 'UMainMenu_Craft_AreaInfoCell_C::Base' has a wrong offset!");
static_assert(offsetof(UMainMenu_Craft_AreaInfoCell_C, Frame) == 0x0003F8, "Member 'UMainMenu_Craft_AreaInfoCell_C::Frame' has a wrong offset!");

}

