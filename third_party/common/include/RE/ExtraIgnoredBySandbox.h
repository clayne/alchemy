#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraIgnoredBySandbox : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraIgnoredBySandbox;


		enum { kExtraTypeID = ExtraDataType::kIgnoredBySandbox };


		virtual ~ExtraIgnoredBySandbox();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kIgnoredBySandbox; }
	};
	static_assert(sizeof(ExtraIgnoredBySandbox) == 0x10);
}
