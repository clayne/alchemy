#pragma once

#include "RE/IMovementInterface.h"


namespace RE
{
	class IMovementPlannerDirectControl : public IMovementInterface
	{
	public:
		inline static const void* RTTI = RTTI_IMovementPlannerDirectControl;


		virtual ~IMovementPlannerDirectControl();	// 00

		// add
		virtual void	Unk_01(void) = 0;			// 01
		virtual void	Unk_02(void) = 0;			// 02
		virtual void	Unk_03(void) = 0;			// 03
		virtual void	Unk_04(void) = 0;			// 04
		virtual void	Unk_05(void) = 0;			// 05
	};
	static_assert(sizeof(IMovementPlannerDirectControl) == 0x8);
}
