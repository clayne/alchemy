#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraWorn : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraWorn;


		enum { kExtraTypeID = ExtraDataType::kWorn };


		virtual ~ExtraWorn();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kWorn; }
	};
	static_assert(sizeof(ExtraWorn) == 0x10);
}
