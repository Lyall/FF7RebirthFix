#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Clip_Voice

#include "Basic.hpp"

#include "EndGame_structs.hpp"


namespace SDK
{

// UserDefinedStruct Clip_Voice.Clip_Voice
// 0x0014 (0x0014 - 0x0000)
struct FClip_Voice final
{
public:
	class FName                                   VoiceName_35_AE6F648142F232AD3900D6BB39044FE0;     // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EEndCutLangType                               Language_45_243AE6BA46865417DCD33596CDBB4A32;      // 0x0008(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_9[0x3];                                        // 0x0009(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   SourceActorName_41_7CBE103D4AF38A0DE2078AA4E45848D0; // 0x000C(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(FClip_Voice) == 0x000004, "Wrong alignment on FClip_Voice");
static_assert(sizeof(FClip_Voice) == 0x000014, "Wrong size on FClip_Voice");
static_assert(offsetof(FClip_Voice, VoiceName_35_AE6F648142F232AD3900D6BB39044FE0) == 0x000000, "Member 'FClip_Voice::VoiceName_35_AE6F648142F232AD3900D6BB39044FE0' has a wrong offset!");
static_assert(offsetof(FClip_Voice, Language_45_243AE6BA46865417DCD33596CDBB4A32) == 0x000008, "Member 'FClip_Voice::Language_45_243AE6BA46865417DCD33596CDBB4A32' has a wrong offset!");
static_assert(offsetof(FClip_Voice, SourceActorName_41_7CBE103D4AF38A0DE2078AA4E45848D0) == 0x00000C, "Member 'FClip_Voice::SourceActorName_41_7CBE103D4AF38A0DE2078AA4E45848D0' has a wrong offset!");

}

