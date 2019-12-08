#pragma once

#include "RE/bhkCharacterState.h"


namespace RE
{
	class bhkCharacterStateSwimming : public bhkCharacterState
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterStateSwimming;


		virtual ~bhkCharacterStateSwimming();						// 00

		// override (bhkCharacterState)
		virtual hkpCharacterStateType	GetType() const override;	// 03 - { return kSwimming; }
		virtual void					Unk_08(void) override;		// 08
	};
	static_assert(sizeof(bhkCharacterStateSwimming) == 0x10);
}