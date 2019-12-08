#pragma once

#include "RE/HeldStateHandler.h"


namespace RE
{
	struct RunHandler : public HeldStateHandler
	{
	public:
		inline static const void* RTTI = RTTI_RunHandler;


		virtual ~RunHandler();																		// 00

		// override (PlayerInputHandler)
		virtual	bool	CanProcess(InputEvent* a_event) override;									// 01
		virtual	void	ProcessButton(ButtonEvent* a_event, MovementData* a_movementData) override;	// 04
	};
	static_assert(sizeof(RunHandler) == 0x18);
}
