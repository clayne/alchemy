#pragma once

#include "RE/IMenu.h"


namespace RE
{
	class MessageBoxMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_MessageBoxMenu;


		virtual ~MessageBoxMenu();											// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04


		// members
		UInt8	unk30;	// 30
		UInt8	pad31;	// 31
		UInt16	pad32;	// 32
		UInt32	pad34;	// 34
	};
	static_assert(sizeof(MessageBoxMenu) == 0x38);
}
