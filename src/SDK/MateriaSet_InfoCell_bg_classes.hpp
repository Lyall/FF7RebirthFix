#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MateriaSet_InfoCell_bg

#include "Basic.hpp"

#include "EndGame_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass MateriaSet_InfoCell_bg.MateriaSet_InfoCell_bg_C
// 0x0008 (0x03D0 - 0x03C8)
class UMateriaSet_InfoCell_bg_C final : public UEndUserWidget
{
public:
	class UEndImage*                              EndImage_68;                                       // 0x03C8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MateriaSet_InfoCell_bg_C">();
	}
	static class UMateriaSet_InfoCell_bg_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMateriaSet_InfoCell_bg_C>();
	}
};
static_assert(alignof(UMateriaSet_InfoCell_bg_C) == 0x000008, "Wrong alignment on UMateriaSet_InfoCell_bg_C");
static_assert(sizeof(UMateriaSet_InfoCell_bg_C) == 0x0003D0, "Wrong size on UMateriaSet_InfoCell_bg_C");
static_assert(offsetof(UMateriaSet_InfoCell_bg_C, EndImage_68) == 0x0003C8, "Member 'UMateriaSet_InfoCell_bg_C::EndImage_68' has a wrong offset!");

}

