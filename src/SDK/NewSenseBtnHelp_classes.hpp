#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: NewSenseBtnHelp

#include "Basic.hpp"

#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass NewSenseBtnHelp.NewSenseBtnHelp_C
// 0x0008 (0x03D0 - 0x03C8)
class UNewSenseBtnHelp_C final : public UEndUserWidget
{
public:
	class UWidgetAnimation*                       MenuOff;                                           // 0x03C8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"NewSenseBtnHelp_C">();
	}
	static class UNewSenseBtnHelp_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UNewSenseBtnHelp_C>();
	}
};
static_assert(alignof(UNewSenseBtnHelp_C) == 0x000008, "Wrong alignment on UNewSenseBtnHelp_C");
static_assert(sizeof(UNewSenseBtnHelp_C) == 0x0003D0, "Wrong size on UNewSenseBtnHelp_C");
static_assert(offsetof(UNewSenseBtnHelp_C, MenuOff) == 0x0003C8, "Member 'UNewSenseBtnHelp_C::MenuOff' has a wrong offset!");

}

