#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESActiveEffectApplyRemoveEvent
	{
		// members
		NiPointer<TESObjectREFR>	caster;			// 00
		NiPointer<TESObjectREFR>	target;			// 08
		UInt16						effectHandle;	// 10
		bool						apply;			// 12
		UInt8						pad13;			// 13
		UInt32						pad14;			// 14
	};
	static_assert(sizeof(TESActiveEffectApplyRemoveEvent) == 0x18);
}
