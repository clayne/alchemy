#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraHeadingTarget : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraHeadingTarget;


		enum { kExtraTypeID = ExtraDataType::kHeadingTarget };


		virtual ~ExtraHeadingTarget();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kHeadingTarget; }


		// members
		UInt64 unk10;	// 10
	};
	static_assert(sizeof(ExtraHeadingTarget) == 0x18);
}
