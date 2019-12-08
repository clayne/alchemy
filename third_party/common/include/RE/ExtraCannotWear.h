#pragma once

#include "RE/BSExtraData.h"


namespace RE
{
	class ExtraCannotWear : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCannotWear;


		enum { kExtraTypeID = ExtraDataType::kCannotWear };


		ExtraCannotWear();
		virtual ~ExtraCannotWear() = default;			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kCannotWear; }
	};
	static_assert(sizeof(ExtraCannotWear) == 0x10);
}