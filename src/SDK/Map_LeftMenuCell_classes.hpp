#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Map_LeftMenuCell

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass Map_LeftMenuCell.Map_LeftMenuCell_C
// 0x0060 (0x0428 - 0x03C8)
class UMap_LeftMenuCell_C final : public UEndUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x03C8(0x0008)(ZeroConstructor, Transient, DuplicateTransient, UObjectWrapper)
	class UWidgetAnimation*                       BtnHover;                                          // 0x03D0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Menu_In;                                           // 0x03D8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UEndImageSet*                           All_Nut_Icon;                                      // 0x03E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage;                                          // 0x03E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage_1;                                        // 0x03F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage_301;                                      // 0x03F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Line;                                              // 0x0400(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              ListPoint_1;                                       // 0x0408(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              ListPoint_2;                                       // 0x0410(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndButton*                             MainMenu_Btn;                                      // 0x0418(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndTextBlock*                          Txt_Title;                                         // 0x0420(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_Map_LeftMenuCell(int32 EntryPoint);
	void BndEvt__MainMenu_Btn_K2Node_ComponentBoundEvent_2_OnButtonHoverEvent__DelegateSignature();
	void BndEvt__MainMenu_Btn_K2Node_ComponentBoundEvent_1_OnButtonHoverEvent__DelegateSignature();
	void Construct();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Map_LeftMenuCell_C">();
	}
	static class UMap_LeftMenuCell_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMap_LeftMenuCell_C>();
	}
};
static_assert(alignof(UMap_LeftMenuCell_C) == 0x000008, "Wrong alignment on UMap_LeftMenuCell_C");
static_assert(sizeof(UMap_LeftMenuCell_C) == 0x000428, "Wrong size on UMap_LeftMenuCell_C");
static_assert(offsetof(UMap_LeftMenuCell_C, UberGraphFrame) == 0x0003C8, "Member 'UMap_LeftMenuCell_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, BtnHover) == 0x0003D0, "Member 'UMap_LeftMenuCell_C::BtnHover' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, Menu_In) == 0x0003D8, "Member 'UMap_LeftMenuCell_C::Menu_In' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, All_Nut_Icon) == 0x0003E0, "Member 'UMap_LeftMenuCell_C::All_Nut_Icon' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, EndImage) == 0x0003E8, "Member 'UMap_LeftMenuCell_C::EndImage' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, EndImage_1) == 0x0003F0, "Member 'UMap_LeftMenuCell_C::EndImage_1' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, EndImage_301) == 0x0003F8, "Member 'UMap_LeftMenuCell_C::EndImage_301' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, Line) == 0x000400, "Member 'UMap_LeftMenuCell_C::Line' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, ListPoint_1) == 0x000408, "Member 'UMap_LeftMenuCell_C::ListPoint_1' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, ListPoint_2) == 0x000410, "Member 'UMap_LeftMenuCell_C::ListPoint_2' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, MainMenu_Btn) == 0x000418, "Member 'UMap_LeftMenuCell_C::MainMenu_Btn' has a wrong offset!");
static_assert(offsetof(UMap_LeftMenuCell_C, Txt_Title) == 0x000420, "Member 'UMap_LeftMenuCell_C::Txt_Title' has a wrong offset!");

}

