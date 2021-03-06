#pragma once

#include "RE/BSTArray.h"
#include "RE/IMenu.h"


namespace RE
{
	struct FileHash;


	class TweenMenu : public IMenu
	{
	public:
		inline static const void* RTTI = RTTI_TweenMenu;


		struct PerkData
		{
			FileHash*	fileHash;	// 00
			const char*	fileName;	// 08
		};
		static_assert(sizeof(PerkData) == 0x10);


		virtual ~TweenMenu();												// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;	// 01
		virtual Result	ProcessMessage(UIMessage* a_message) override;		// 04
		virtual void	Render() override;									// 06


		// members
		BSTArray<PerkData>	perkData;	// 30
		float				unk48;		// 48
		float				unk4C;		// 4C
	};
	static_assert(sizeof(TweenMenu) == 0x50);
}
