#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MainMenu_Card_Card_Full

#include "Basic.hpp"

#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass MainMenu_Card_Card_Full.MainMenu_Card_Card_Full_C
// 0x0178 (0x0748 - 0x05D0)
class UMainMenu_Card_Card_Full_C final : public UEndCardGameCardPane
{
public:
	class UWidgetAnimation*                       Card_In_x2;                                        // 0x05D0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       CardNum_EditMenu;                                  // 0x05D8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       CardNum_x2;                                        // 0x05E0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_UnHover;                                      // 0x05E8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_Hover;                                        // 0x05F0(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_PlusIn;                                       // 0x05F8(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_None;                                         // 0x0600(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_Lock_NoneText;                                // 0x0608(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_Lock;                                         // 0x0610(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_RarityL;                                      // 0x0618(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_RarityN;                                      // 0x0620(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_Mulligan;                                     // 0x0628(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_Enemy;                                        // 0x0630(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_Player;                                       // 0x0638(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_In;                                           // 0x0640(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_Out;                                          // 0x0648(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_Unavaliable;                                  // 0x0650(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_Selected;                                     // 0x0658(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       Card_Normal;                                       // 0x0660(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UEndBillboard*                          Billboard_Base_L;                                  // 0x0668(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndBillboard*                          Billboard_Base_N;                                  // 0x0670(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndBillboard*                          Billboard_Bg;                                      // 0x0678(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndBillboard*                          Billboard_CardBack;                                // 0x0680(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndBillboard*                          Billboard_Thumbnail;                               // 0x0688(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndButton*                             Card_Btn;                                          // 0x0690(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMainMenu_Card_CardCursor_C*            CardCursor;                                        // 0x0698(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndFlagGrid*                           FlagGrid;                                          // 0x06A0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_AvaliableFrame;                                // 0x06A8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_Base;                                          // 0x06B0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_BaseNew;                                       // 0x06B8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_CardBack;                                      // 0x06C0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_CardNameBase;                                  // 0x06C8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_FlagBase_01;                                   // 0x06D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_FlagBase_02;                                   // 0x06D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_Light_In;                                      // 0x06E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_Light_In_1;                                    // 0x06E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_Light_In_2;                                    // 0x06F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_LimitBase;                                     // 0x06F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_MpBase;                                        // 0x0700(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_Mulligan_Base;                                 // 0x0708(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_Mulligan_Icon;                                 // 0x0710(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_OverwriteCard;                                 // 0x0718(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_PowerBase;                                     // 0x0720(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_SkillIcon;                                     // 0x0728(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImage*                              Img_X;                                             // 0x0730(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndImageSet*                           ImgSet_Power;                                      // 0x0738(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UEndNumberLabel*                        NumLabel;                                          // 0x0740(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MainMenu_Card_Card_Full_C">();
	}
	static class UMainMenu_Card_Card_Full_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMainMenu_Card_Card_Full_C>();
	}
};
static_assert(alignof(UMainMenu_Card_Card_Full_C) == 0x000008, "Wrong alignment on UMainMenu_Card_Card_Full_C");
static_assert(sizeof(UMainMenu_Card_Card_Full_C) == 0x000748, "Wrong size on UMainMenu_Card_Card_Full_C");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_In_x2) == 0x0005D0, "Member 'UMainMenu_Card_Card_Full_C::Card_In_x2' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, CardNum_EditMenu) == 0x0005D8, "Member 'UMainMenu_Card_Card_Full_C::CardNum_EditMenu' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, CardNum_x2) == 0x0005E0, "Member 'UMainMenu_Card_Card_Full_C::CardNum_x2' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_UnHover) == 0x0005E8, "Member 'UMainMenu_Card_Card_Full_C::Card_UnHover' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Hover) == 0x0005F0, "Member 'UMainMenu_Card_Card_Full_C::Card_Hover' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_PlusIn) == 0x0005F8, "Member 'UMainMenu_Card_Card_Full_C::Card_PlusIn' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_None) == 0x000600, "Member 'UMainMenu_Card_Card_Full_C::Card_None' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Lock_NoneText) == 0x000608, "Member 'UMainMenu_Card_Card_Full_C::Card_Lock_NoneText' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Lock) == 0x000610, "Member 'UMainMenu_Card_Card_Full_C::Card_Lock' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_RarityL) == 0x000618, "Member 'UMainMenu_Card_Card_Full_C::Card_RarityL' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_RarityN) == 0x000620, "Member 'UMainMenu_Card_Card_Full_C::Card_RarityN' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Mulligan) == 0x000628, "Member 'UMainMenu_Card_Card_Full_C::Card_Mulligan' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Enemy) == 0x000630, "Member 'UMainMenu_Card_Card_Full_C::Card_Enemy' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Player) == 0x000638, "Member 'UMainMenu_Card_Card_Full_C::Card_Player' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_In) == 0x000640, "Member 'UMainMenu_Card_Card_Full_C::Card_In' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Out) == 0x000648, "Member 'UMainMenu_Card_Card_Full_C::Card_Out' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Unavaliable) == 0x000650, "Member 'UMainMenu_Card_Card_Full_C::Card_Unavaliable' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Selected) == 0x000658, "Member 'UMainMenu_Card_Card_Full_C::Card_Selected' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Normal) == 0x000660, "Member 'UMainMenu_Card_Card_Full_C::Card_Normal' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Billboard_Base_L) == 0x000668, "Member 'UMainMenu_Card_Card_Full_C::Billboard_Base_L' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Billboard_Base_N) == 0x000670, "Member 'UMainMenu_Card_Card_Full_C::Billboard_Base_N' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Billboard_Bg) == 0x000678, "Member 'UMainMenu_Card_Card_Full_C::Billboard_Bg' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Billboard_CardBack) == 0x000680, "Member 'UMainMenu_Card_Card_Full_C::Billboard_CardBack' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Billboard_Thumbnail) == 0x000688, "Member 'UMainMenu_Card_Card_Full_C::Billboard_Thumbnail' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Card_Btn) == 0x000690, "Member 'UMainMenu_Card_Card_Full_C::Card_Btn' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, CardCursor) == 0x000698, "Member 'UMainMenu_Card_Card_Full_C::CardCursor' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, FlagGrid) == 0x0006A0, "Member 'UMainMenu_Card_Card_Full_C::FlagGrid' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_AvaliableFrame) == 0x0006A8, "Member 'UMainMenu_Card_Card_Full_C::Img_AvaliableFrame' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_Base) == 0x0006B0, "Member 'UMainMenu_Card_Card_Full_C::Img_Base' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_BaseNew) == 0x0006B8, "Member 'UMainMenu_Card_Card_Full_C::Img_BaseNew' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_CardBack) == 0x0006C0, "Member 'UMainMenu_Card_Card_Full_C::Img_CardBack' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_CardNameBase) == 0x0006C8, "Member 'UMainMenu_Card_Card_Full_C::Img_CardNameBase' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_FlagBase_01) == 0x0006D0, "Member 'UMainMenu_Card_Card_Full_C::Img_FlagBase_01' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_FlagBase_02) == 0x0006D8, "Member 'UMainMenu_Card_Card_Full_C::Img_FlagBase_02' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_Light_In) == 0x0006E0, "Member 'UMainMenu_Card_Card_Full_C::Img_Light_In' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_Light_In_1) == 0x0006E8, "Member 'UMainMenu_Card_Card_Full_C::Img_Light_In_1' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_Light_In_2) == 0x0006F0, "Member 'UMainMenu_Card_Card_Full_C::Img_Light_In_2' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_LimitBase) == 0x0006F8, "Member 'UMainMenu_Card_Card_Full_C::Img_LimitBase' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_MpBase) == 0x000700, "Member 'UMainMenu_Card_Card_Full_C::Img_MpBase' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_Mulligan_Base) == 0x000708, "Member 'UMainMenu_Card_Card_Full_C::Img_Mulligan_Base' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_Mulligan_Icon) == 0x000710, "Member 'UMainMenu_Card_Card_Full_C::Img_Mulligan_Icon' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_OverwriteCard) == 0x000718, "Member 'UMainMenu_Card_Card_Full_C::Img_OverwriteCard' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_PowerBase) == 0x000720, "Member 'UMainMenu_Card_Card_Full_C::Img_PowerBase' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_SkillIcon) == 0x000728, "Member 'UMainMenu_Card_Card_Full_C::Img_SkillIcon' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, Img_X) == 0x000730, "Member 'UMainMenu_Card_Card_Full_C::Img_X' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, ImgSet_Power) == 0x000738, "Member 'UMainMenu_Card_Card_Full_C::ImgSet_Power' has a wrong offset!");
static_assert(offsetof(UMainMenu_Card_Card_Full_C, NumLabel) == 0x000740, "Member 'UMainMenu_Card_Card_Full_C::NumLabel' has a wrong offset!");

}

