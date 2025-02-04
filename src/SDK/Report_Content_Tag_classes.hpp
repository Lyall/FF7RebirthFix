#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Report_Content_Tag

#include "Basic.hpp"

#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass Report_Content_Tag.Report_Content_Tag_C
// 0x0030 (0x03F8 - 0x03C8)
class UReport_Content_Tag_C final : public UEndUserWidget
{
public:
	class UWidgetAnimation*                       On;                                                // 0x03C8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Off;                                               // 0x03D0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UEndImage*                              Base;                                              // 0x03D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Frame;                                             // 0x03E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImageSet*                           Icon_Clear;                                        // 0x03E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImageSet*                           IconSet;                                           // 0x03F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Report_Content_Tag_C">();
	}
	static class UReport_Content_Tag_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UReport_Content_Tag_C>();
	}
};
static_assert(alignof(UReport_Content_Tag_C) == 0x000008, "Wrong alignment on UReport_Content_Tag_C");
static_assert(sizeof(UReport_Content_Tag_C) == 0x0003F8, "Wrong size on UReport_Content_Tag_C");
static_assert(offsetof(UReport_Content_Tag_C, On) == 0x0003C8, "Member 'UReport_Content_Tag_C::On' has a wrong offset!");
static_assert(offsetof(UReport_Content_Tag_C, Off) == 0x0003D0, "Member 'UReport_Content_Tag_C::Off' has a wrong offset!");
static_assert(offsetof(UReport_Content_Tag_C, Base) == 0x0003D8, "Member 'UReport_Content_Tag_C::Base' has a wrong offset!");
static_assert(offsetof(UReport_Content_Tag_C, Frame) == 0x0003E0, "Member 'UReport_Content_Tag_C::Frame' has a wrong offset!");
static_assert(offsetof(UReport_Content_Tag_C, Icon_Clear) == 0x0003E8, "Member 'UReport_Content_Tag_C::Icon_Clear' has a wrong offset!");
static_assert(offsetof(UReport_Content_Tag_C, IconSet) == 0x0003F0, "Member 'UReport_Content_Tag_C::IconSet' has a wrong offset!");

}

