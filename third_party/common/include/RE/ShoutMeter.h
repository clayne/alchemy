#pragma once

#include "RE/HUDMeter.h"


namespace RE
{
	class ShoutMeter : public HUDMeter
	{
	public:
		inline static const void* RTTI = RTTI_ShoutMeter;


		virtual ~ShoutMeter();											// 00

		// override (HUDMeter)
		virtual bool	ProcessMessage(UIMessage* a_message) override;	// 02
		virtual float	GetFillPct() override;							// 05


		// members
		float	cooldown;	// 48 - in seconds
		UInt32	unk4C;		// 4C
	};
	static_assert(sizeof(ShoutMeter) == 0x50);
}