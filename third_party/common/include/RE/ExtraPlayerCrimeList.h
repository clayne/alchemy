#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraPlayerCrimeList : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPlayerCrimeList;


		enum { kExtraTypeID = ExtraDataType::kPlayerCrimeList };


		virtual ~ExtraPlayerCrimeList();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kPlayerCrimeList; }


		// members
		BSSimpleList<UInt64>* unk10;	// 10
	};
	static_assert(sizeof(ExtraPlayerCrimeList) == 0x18);
}
