#pragma once

#include "RE/bhkCharacterState.h"


namespace RE
{
	class bhkCharacterStateInAir : public bhkCharacterState
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterStateInAir;


		virtual ~bhkCharacterStateInAir();							// 00

		// override (bhkCharacterState)
		virtual hkpCharacterStateType	GetType() const override;	// 03 - { return kInAir; }
		virtual void					Unk_08(void) override;		// 08


		// members
		UInt64 unk10;	// 10
	};
	static_assert(sizeof(bhkCharacterStateInAir) == 0x18);
}
