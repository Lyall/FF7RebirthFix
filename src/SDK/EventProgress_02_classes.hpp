#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: EventProgress_02

#include "Basic.hpp"

#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass EventProgress_02.EventProgress_02_C
// 0x0060 (0x0428 - 0x03C8)
class UEventProgress_02_C final : public UEndUserWidget
{
public:
	class UWidgetAnimation*                       Out;                                               // 0x03C8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       In;                                                // 0x03D0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UEndImage*                              Effect_StatusTxtBG;                                // 0x03D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Effect_StatusTxtBG_1;                              // 0x03E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_BG;                                            // 0x03E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImageSet*                           Ims_Effect_StatusTxt;                              // 0x03F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Line_Bottom_Left;                                  // 0x03F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Line_Bottom_Right;                                 // 0x0400(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Line_Top_Left;                                     // 0x0408(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Line_Top_Right;                                    // 0x0410(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImageSet*                           Squere_Bottom;                                     // 0x0418(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImageSet*                           Squere_Top;                                        // 0x0420(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"EventProgress_02_C">();
	}
	static class UEventProgress_02_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UEventProgress_02_C>();
	}
};
static_assert(alignof(UEventProgress_02_C) == 0x000008, "Wrong alignment on UEventProgress_02_C");
static_assert(sizeof(UEventProgress_02_C) == 0x000428, "Wrong size on UEventProgress_02_C");
static_assert(offsetof(UEventProgress_02_C, Out) == 0x0003C8, "Member 'UEventProgress_02_C::Out' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, In) == 0x0003D0, "Member 'UEventProgress_02_C::In' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, Effect_StatusTxtBG) == 0x0003D8, "Member 'UEventProgress_02_C::Effect_StatusTxtBG' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, Effect_StatusTxtBG_1) == 0x0003E0, "Member 'UEventProgress_02_C::Effect_StatusTxtBG_1' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, Img_BG) == 0x0003E8, "Member 'UEventProgress_02_C::Img_BG' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, Ims_Effect_StatusTxt) == 0x0003F0, "Member 'UEventProgress_02_C::Ims_Effect_StatusTxt' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, Line_Bottom_Left) == 0x0003F8, "Member 'UEventProgress_02_C::Line_Bottom_Left' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, Line_Bottom_Right) == 0x000400, "Member 'UEventProgress_02_C::Line_Bottom_Right' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, Line_Top_Left) == 0x000408, "Member 'UEventProgress_02_C::Line_Top_Left' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, Line_Top_Right) == 0x000410, "Member 'UEventProgress_02_C::Line_Top_Right' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, Squere_Bottom) == 0x000418, "Member 'UEventProgress_02_C::Squere_Bottom' has a wrong offset!");
static_assert(offsetof(UEventProgress_02_C, Squere_Top) == 0x000420, "Member 'UEventProgress_02_C::Squere_Top' has a wrong offset!");

}

