#pragma once

#include "RE/IMenu.h"


namespace RE
{
	namespace CraftingSubMenus
	{
		class CraftingSubMenu;
	}


	class CraftingMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_CraftingMenu;


		virtual ~CraftingMenu();												// 00

		// override (IMenu)
		virtual Result	ProcessMessage(UIMessage* a_message) override;			// 04
		virtual void	NextFrame(float a_arg1, UInt32 a_currentTime) override;	// 05
		virtual void	Render() override;										// 06


		// members
		CraftingSubMenus::CraftingSubMenu* subMenu;	// 30
	};
	static_assert(sizeof(CraftingMenu) == 0x38);
}
