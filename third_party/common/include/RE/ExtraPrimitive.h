#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraPrimitive : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPrimitive;


		enum { kExtraTypeID = ExtraDataType::kPrimitive };


		virtual ~ExtraPrimitive();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kPrimitive; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		void* unk10;	// 10
	};
	static_assert(sizeof(ExtraPrimitive) == 0x18);
}
