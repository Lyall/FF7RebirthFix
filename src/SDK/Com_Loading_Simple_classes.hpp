#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Com_Loading_Simple

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass Com_Loading_Simple.Com_Loading_Simple_C
// 0x00D8 (0x04A0 - 0x03C8)
class UCom_Loading_Simple_C final : public UEndUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x03C8(0x0008)(ZeroConstructor, Transient, DuplicateTransient, UObjectWrapper)
	class UWidgetAnimation*                       Loop2_old;                                         // 0x03D0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Loop2;                                             // 0x03D8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UEndCanvasPanel*                        All_Com_Loading;                                   // 0x03E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndBorder*                             All_Nut_LoadingText;                               // 0x03E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              BaseLight;                                         // 0x03F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Block1;                                            // 0x03F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Block2;                                            // 0x0400(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Block3;                                            // 0x0408(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Block4;                                            // 0x0410(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Block5;                                            // 0x0418(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Block6;                                            // 0x0420(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Block7;                                            // 0x0428(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Block8;                                            // 0x0430(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage_22;                                       // 0x0438(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage_23;                                       // 0x0440(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage_24;                                       // 0x0448(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage_25;                                       // 0x0450(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage_26;                                       // 0x0458(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage_27;                                       // 0x0460(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage_28;                                       // 0x0468(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              EndImage_29;                                       // 0x0470(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Icon_1;                                            // 0x0478(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Icon_2;                                            // 0x0480(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Icon_3;                                            // 0x0488(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndCanvasPanel*                        Pnl_LoadingText;                                   // 0x0490(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndTextBlock*                          Txt_Loading;                                       // 0x0498(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_Com_Loading_Simple(int32 EntryPoint);
	void Construct();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Com_Loading_Simple_C">();
	}
	static class UCom_Loading_Simple_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCom_Loading_Simple_C>();
	}
};
static_assert(alignof(UCom_Loading_Simple_C) == 0x000008, "Wrong alignment on UCom_Loading_Simple_C");
static_assert(sizeof(UCom_Loading_Simple_C) == 0x0004A0, "Wrong size on UCom_Loading_Simple_C");
static_assert(offsetof(UCom_Loading_Simple_C, UberGraphFrame) == 0x0003C8, "Member 'UCom_Loading_Simple_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Loop2_old) == 0x0003D0, "Member 'UCom_Loading_Simple_C::Loop2_old' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Loop2) == 0x0003D8, "Member 'UCom_Loading_Simple_C::Loop2' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, All_Com_Loading) == 0x0003E0, "Member 'UCom_Loading_Simple_C::All_Com_Loading' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, All_Nut_LoadingText) == 0x0003E8, "Member 'UCom_Loading_Simple_C::All_Nut_LoadingText' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, BaseLight) == 0x0003F0, "Member 'UCom_Loading_Simple_C::BaseLight' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Block1) == 0x0003F8, "Member 'UCom_Loading_Simple_C::Block1' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Block2) == 0x000400, "Member 'UCom_Loading_Simple_C::Block2' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Block3) == 0x000408, "Member 'UCom_Loading_Simple_C::Block3' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Block4) == 0x000410, "Member 'UCom_Loading_Simple_C::Block4' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Block5) == 0x000418, "Member 'UCom_Loading_Simple_C::Block5' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Block6) == 0x000420, "Member 'UCom_Loading_Simple_C::Block6' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Block7) == 0x000428, "Member 'UCom_Loading_Simple_C::Block7' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Block8) == 0x000430, "Member 'UCom_Loading_Simple_C::Block8' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, EndImage_22) == 0x000438, "Member 'UCom_Loading_Simple_C::EndImage_22' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, EndImage_23) == 0x000440, "Member 'UCom_Loading_Simple_C::EndImage_23' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, EndImage_24) == 0x000448, "Member 'UCom_Loading_Simple_C::EndImage_24' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, EndImage_25) == 0x000450, "Member 'UCom_Loading_Simple_C::EndImage_25' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, EndImage_26) == 0x000458, "Member 'UCom_Loading_Simple_C::EndImage_26' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, EndImage_27) == 0x000460, "Member 'UCom_Loading_Simple_C::EndImage_27' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, EndImage_28) == 0x000468, "Member 'UCom_Loading_Simple_C::EndImage_28' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, EndImage_29) == 0x000470, "Member 'UCom_Loading_Simple_C::EndImage_29' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Icon_1) == 0x000478, "Member 'UCom_Loading_Simple_C::Icon_1' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Icon_2) == 0x000480, "Member 'UCom_Loading_Simple_C::Icon_2' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Icon_3) == 0x000488, "Member 'UCom_Loading_Simple_C::Icon_3' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Pnl_LoadingText) == 0x000490, "Member 'UCom_Loading_Simple_C::Pnl_LoadingText' has a wrong offset!");
static_assert(offsetof(UCom_Loading_Simple_C, Txt_Loading) == 0x000498, "Member 'UCom_Loading_Simple_C::Txt_Loading' has a wrong offset!");

}

