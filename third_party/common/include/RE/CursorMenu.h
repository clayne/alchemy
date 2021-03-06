#pragma once

#include "RE/IMenu.h"
#include "RE/MenuEventHandler.h"


namespace RE
{
	class CursorMenu :
		public IMenu,			// 00
		public MenuEventHandler	// 30
	{
	public:
		inline static const void* RTTI = RTTI_CursorMenu;


		virtual ~CursorMenu();													// 00

		// override (IMenu)
		virtual Result	ProcessMessage(UIMessage* a_message) override;			// 04

		// override (MenuEventHandler)
		virtual bool	CanProcess(InputEvent* a_event) override;				// 01
		virtual bool	ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03
		virtual bool	ProcessMouseMove(MouseMoveEvent* a_event) override;		// 04
	};
	static_assert(sizeof(CursorMenu) == 0x40);
}
