#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MobPrefabTemplate_LookAtAndContact_04

#include "Basic.hpp"

#include "MobPrefabTemplate_LookAtAndContact_03_classes.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass MobPrefabTemplate_LookAtAndContact_04.MobPrefabTemplate_LookAtAndContact_04_C
// 0x0240 (0x0E00 - 0x0BC0)
class AMobPrefabTemplate_LookAtAndContact_04_C : public AMobPrefabTemplate_LookAtAndContact_03_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_MobPrefabTemplate_LookAtAndContact_04_C; // 0x0BC0(0x0008)(ZeroConstructor, Transient, DuplicateTransient, UObjectWrapper)
	TSoftClassPtr<class UClass>                   CharacterClass04;                                  // 0x0BC8(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, UObjectWrapper, HasGetValueTypeHash)
	class FName                                   LoopMotionName04;                                  // 0x0BF0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSoftClassPtr<class UClass>                   AttachActor04;                                     // 0x0BF8(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	class FName                                   AttachSocketName04;                                // 0x0C20(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          EnableLookAt04;                                    // 0x0C28(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          EnableContact04;                                   // 0x0C29(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          ContactDuringReaction04;                           // 0x0C2A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_C2B[0x1];                                      // 0x0C2B(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   ContactForwardLeftMotionName04;                    // 0x0C2C(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   ContactForwardRightMotionName04;                   // 0x0C34(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   ContactBackLeftMotionName04;                       // 0x0C3C(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   ContactBackRightMotionName04;                      // 0x0C44(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ContactBlendTime04;                                // 0x0C4C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TMap<class FName, class FName>                ContactPropagateMotionTable04;                     // 0x0C50(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	TMap<class FName, class FName>                ContactPropagateForwardLeftMotionTable04;          // 0x0CA0(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	TMap<class FName, class FName>                ContactPropagateForwardRightMotionTable04;         // 0x0CF0(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	TMap<class FName, class FName>                ContactPropagateBackLeftMotionTable04;             // 0x0D40(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	TMap<class FName, class FName>                ContactPropagateBackRightMotionTable04;            // 0x0D90(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	float                                         ContactPropagateBlendTime04;                       // 0x0DE0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   ContactOutMotionName04;                            // 0x0DE4(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ContactOutBlendTime04;                             // 0x0DEC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   ContactOutReplaceBaseMotionName04;                 // 0x0DF0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_MobPrefabTemplate_LookAtAndContact_04(int32 EntryPoint);
	void OnPreUpdateRegistry();
	void GetContext(class FName MobId, bool* EnableLookAt, bool* EnableContact, bool* ContactDuringReaction, class FName* ForwardLeftMotion, class FName* ForwardRightMotion, class FName* BackLeftMotion, class FName* BackRightMotion, float* ContactBlendTime, TMap<class FName, class FName>* ContactPropagateMotionTable, TMap<class FName, class FName>* ContactPropagateForwardLeftMotionTable, TMap<class FName, class FName>* ContactPropagateForwardRightMotionTable, TMap<class FName, class FName>* ContactPropagateBackLeftMotionTable, TMap<class FName, class FName>* ContactPropagateBackRightMotionTable, float* ContactPropagateBlendTime, class FName* ContactOutMotionName, float* ContactOutBlendTime, class FName* ContactOutReplaceBaseMotionName);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MobPrefabTemplate_LookAtAndContact_04_C">();
	}
	static class AMobPrefabTemplate_LookAtAndContact_04_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AMobPrefabTemplate_LookAtAndContact_04_C>();
	}
};
static_assert(alignof(AMobPrefabTemplate_LookAtAndContact_04_C) == 0x000010, "Wrong alignment on AMobPrefabTemplate_LookAtAndContact_04_C");
static_assert(sizeof(AMobPrefabTemplate_LookAtAndContact_04_C) == 0x000E00, "Wrong size on AMobPrefabTemplate_LookAtAndContact_04_C");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, UberGraphFrame_MobPrefabTemplate_LookAtAndContact_04_C) == 0x000BC0, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::UberGraphFrame_MobPrefabTemplate_LookAtAndContact_04_C' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, CharacterClass04) == 0x000BC8, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::CharacterClass04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, LoopMotionName04) == 0x000BF0, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::LoopMotionName04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, AttachActor04) == 0x000BF8, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::AttachActor04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, AttachSocketName04) == 0x000C20, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::AttachSocketName04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, EnableLookAt04) == 0x000C28, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::EnableLookAt04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, EnableContact04) == 0x000C29, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::EnableContact04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactDuringReaction04) == 0x000C2A, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactDuringReaction04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactForwardLeftMotionName04) == 0x000C2C, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactForwardLeftMotionName04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactForwardRightMotionName04) == 0x000C34, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactForwardRightMotionName04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactBackLeftMotionName04) == 0x000C3C, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactBackLeftMotionName04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactBackRightMotionName04) == 0x000C44, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactBackRightMotionName04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactBlendTime04) == 0x000C4C, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactBlendTime04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactPropagateMotionTable04) == 0x000C50, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactPropagateMotionTable04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactPropagateForwardLeftMotionTable04) == 0x000CA0, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactPropagateForwardLeftMotionTable04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactPropagateForwardRightMotionTable04) == 0x000CF0, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactPropagateForwardRightMotionTable04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactPropagateBackLeftMotionTable04) == 0x000D40, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactPropagateBackLeftMotionTable04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactPropagateBackRightMotionTable04) == 0x000D90, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactPropagateBackRightMotionTable04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactPropagateBlendTime04) == 0x000DE0, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactPropagateBlendTime04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactOutMotionName04) == 0x000DE4, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactOutMotionName04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactOutBlendTime04) == 0x000DEC, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactOutBlendTime04' has a wrong offset!");
static_assert(offsetof(AMobPrefabTemplate_LookAtAndContact_04_C, ContactOutReplaceBaseMotionName04) == 0x000DF0, "Member 'AMobPrefabTemplate_LookAtAndContact_04_C::ContactOutReplaceBaseMotionName04' has a wrong offset!");

}

