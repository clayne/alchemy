#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraLockList : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLockList;


		enum { kExtraTypeID = ExtraDataType::kLockList };


		virtual ~ExtraLockList();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { reutrn kLockList; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		UInt64 unk10;	// 10
	};
	static_assert(sizeof(ExtraLockList) == 0x18);
}
