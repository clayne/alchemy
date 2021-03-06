#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraObjectHealth : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraObjectHealth;


		enum { kExtraTypeID = ExtraDataType::kObjectHealth };


		virtual ~ExtraObjectHealth();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kObjectHealth; }


		// members
		float	health;	// 10
		UInt32	pad14;	// 14
	};
	static_assert(sizeof(ExtraObjectHealth) == 0x18);
}
