#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiRefObject;


	class ExtraHavok : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraHavok;


		enum { kExtraTypeID = ExtraDataType::kHavok };


		virtual ~ExtraHavok();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kHavok; }


		// members
		NiPointer<NiRefObject>	unk10;	// 10
		NiPointer<NiRefObject>	unk18;	// 18
	};
	static_assert(sizeof(ExtraHavok) == 0x20);
}
