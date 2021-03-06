#pragma once

#include "RE/IMovementInterface.h"


namespace RE
{
	class IMovementMessageInterface : public IMovementInterface
	{
	public:
		inline static const void* RTTI = RTTI_IMovementMessageInterface;


		virtual ~IMovementMessageInterface();	// 00

		// add
		virtual void	Unk_01(void) = 0;		// 01
		virtual void	Unk_02(void) = 0;		// 02
		virtual void	Unk_03(void) = 0;		// 03
	};
	static_assert(sizeof(IMovementMessageInterface) == 0x8);
}
