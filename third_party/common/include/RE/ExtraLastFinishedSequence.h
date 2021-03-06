#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSFixedString.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraLastFinishedSequence : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLastFinishedSequence;


		enum { kExtraTypeID = ExtraDataType::kLastFinishedSequence };


		virtual ~ExtraLastFinishedSequence();											// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kLastFinishedSequence; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return sequence != a_rhs->sequence; }


		// members
		BSFixedString sequence;	// 10
	};
	static_assert(sizeof(ExtraLastFinishedSequence) == 0x18);
}
