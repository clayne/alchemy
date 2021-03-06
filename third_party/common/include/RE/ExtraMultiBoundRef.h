#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/FormTypes.h"


namespace RE
{
	class ExtraMultiBoundRef : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraMultiBoundRef;


		enum { kExtraTypeID = ExtraDataType::kMultiBoundRef };


		virtual ~ExtraMultiBoundRef();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kMultiBoundRef; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return ref != a_rhs->ref; }

		// members
		TESObjectREFR* ref;	// 10
	};
	static_assert(sizeof(ExtraMultiBoundRef) == 0x18);
}
