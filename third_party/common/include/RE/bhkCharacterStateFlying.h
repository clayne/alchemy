#pragma once

#include "RE/bhkCharacterState.h"


namespace RE
{
	class bhkCharacterStateFlying : public bhkCharacterState
	{
	public:
		inline static const void* RTTI = RTTI_bhkCharacterStateFlying;


		virtual ~bhkCharacterStateFlying();							// 00

		// override (bhkCharacterState)
		virtual hkpCharacterStateType	GetType() const override;	// 03 - { return kFlying; }
		virtual void					Unk_08(void) override;		// 08
	};
	static_assert(sizeof(bhkCharacterStateFlying) == 0x10);
}
