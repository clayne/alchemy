#pragma once

#include "RE/IMenu.h"


namespace RE
{
	class FaderMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_FaderMenu;


		virtual ~FaderMenu();											// 00

		// override (IMenu)
		virtual Result ProcessMessage(UIMessage* a_message) override;	// 04


		// members
		void*	unk30;	// 30 - smart ptr
		UInt8	unk38;	// 38
		UInt8	unk39;	// 39
		UInt16	pad3A;	// 3A
		UInt32	pad3C;	// 3C
	};
	static_assert(sizeof(FaderMenu) == 0x40);
}
