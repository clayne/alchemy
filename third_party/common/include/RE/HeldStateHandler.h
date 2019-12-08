#pragma once

#include "RE/PlayerInputHandler.h"


namespace RE
{
	class HeldStateHandler : public PlayerInputHandler
	{
	public:
		inline static const void* RTTI = RTTI_HeldStateHandler;


		virtual ~HeldStateHandler();				// 00

		// add
		virtual void	Unk_05(void);				// 05
		virtual void	SetHeldState(bool a_held);	// 06 - { isHeld = a_held; }


		// members
		bool	isHeld;	// 10
		UInt8	pad11;	// 11
		UInt16	pad12;	// 12
		UInt32	pad14;	// 14
	};
	static_assert(sizeof(HeldStateHandler) == 0x18);
}
