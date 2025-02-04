#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Icon_Status

#include "Basic.hpp"

#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass Icon_Status.Icon_Status_C
// 0x0030 (0x03F8 - 0x03C8)
class UIcon_Status_C final : public UEndUserWidget
{
public:
	class UEndImageSet*                           All_Nut_Icon_Status;                               // 0x03C8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Gauge_Base;                                        // 0x03D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndPieImage*                           Gauge_Time;                                        // 0x03D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImageSet*                           Icon_Resistances;                                  // 0x03E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              LockFrame;                                         // 0x03E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndGauge*                              StoneGauge;                                        // 0x03F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Icon_Status_C">();
	}
	static class UIcon_Status_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UIcon_Status_C>();
	}
};
static_assert(alignof(UIcon_Status_C) == 0x000008, "Wrong alignment on UIcon_Status_C");
static_assert(sizeof(UIcon_Status_C) == 0x0003F8, "Wrong size on UIcon_Status_C");
static_assert(offsetof(UIcon_Status_C, All_Nut_Icon_Status) == 0x0003C8, "Member 'UIcon_Status_C::All_Nut_Icon_Status' has a wrong offset!");
static_assert(offsetof(UIcon_Status_C, Gauge_Base) == 0x0003D0, "Member 'UIcon_Status_C::Gauge_Base' has a wrong offset!");
static_assert(offsetof(UIcon_Status_C, Gauge_Time) == 0x0003D8, "Member 'UIcon_Status_C::Gauge_Time' has a wrong offset!");
static_assert(offsetof(UIcon_Status_C, Icon_Resistances) == 0x0003E0, "Member 'UIcon_Status_C::Icon_Resistances' has a wrong offset!");
static_assert(offsetof(UIcon_Status_C, LockFrame) == 0x0003E8, "Member 'UIcon_Status_C::LockFrame' has a wrong offset!");
static_assert(offsetof(UIcon_Status_C, StoneGauge) == 0x0003F0, "Member 'UIcon_Status_C::StoneGauge' has a wrong offset!");

}

