#pragma once

#include "RE/bhkPhantom.h"


namespace RE
{
	class bhkShapePhantom : public bhkPhantom
	{
	public:
		inline static const void* RTTI = RTTI_bhkShapePhantom;
		inline static const void* Ni_RTTI = NiRTTI_bhkShapePhantom;


		virtual ~bhkShapePhantom();											// 00

		// override (bhkPhantom)
		virtual const NiRTTI*	GetRTTI() const override;					// 02
		virtual void			LinkObject(NiStream& a_stream) override;	// 19 - { bhkWorldObject::LinkObject(a_stream); }
	};
	static_assert(sizeof(bhkShapePhantom) == 0x30);
}