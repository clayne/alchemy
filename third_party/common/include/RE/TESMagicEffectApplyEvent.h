#pragma once

#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	struct TESMagicEffectApplyEvent
	{
		NiPointer<TESObjectREFR>	target;	// 00
		NiPointer<TESObjectREFR>	caster;	// 08
		FormID						effect;	// 10
		UInt32						pad14;	// 14
	};
	static_assert(sizeof(TESMagicEffectApplyEvent) == 0x18);
}
