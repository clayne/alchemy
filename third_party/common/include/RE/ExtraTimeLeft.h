#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraTimeLeft : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraTimeLeft;


		enum { kExtraTypeID = ExtraDataType::kTimeLeft };


		virtual ~ExtraTimeLeft();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kTimeLeft; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		float	unk10;	// 10
		UInt32	pad14;	// 14
	};
	static_assert(sizeof(ExtraTimeLeft) == 0x18);
}
