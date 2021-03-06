#pragma once

#include "RE/bhkShape.h"


namespace RE
{
	class bhkShapeCollection : public bhkShape
	{
	public:
		inline static const void* RTTI = RTTI_bhkShapeCollection;
		inline static const void* Ni_RTTI = NiRTTI_bhkShapeCollection;


		virtual ~bhkShapeCollection();						// 00

		// override (bhkShape)
		virtual const NiRTTI*	GetRTTI() const override;	// 02
		virtual void			Unk_34(void) override;		// 34 - { return this; }
		virtual void			Unk_35(void) override;		// 35

		// add
		virtual void			Unk_36(void) = 0;			// 36
	};
	static_assert(sizeof(bhkShapeCollection) == 0x28);
}
