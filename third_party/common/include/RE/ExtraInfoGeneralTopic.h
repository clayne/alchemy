#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraInfoGeneralTopic : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraInfoGeneralTopic;


		enum { kExtraTypeID = ExtraDataType::kInfoGeneralTopic };


		struct Data
		{
			UInt64	unk00;	// 00
			UInt64	unk08;	// 08
			UInt64	unk10;	// 10
			UInt64	unk18;	// 18
			UInt64	unk20;	// 20
			UInt64	unk28;	// 28
			UInt64	unk30;	// 30
			UInt64	unk38;	// 38
			UInt64	unk40;	// 40
			UInt64	unk48;	// 48
			UInt64	unk50;	// 50
		};
		static_assert(sizeof(Data) == 0x58);


		virtual ~ExtraInfoGeneralTopic();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kInfoGeneralTopic; }


		// members
		Data* unk10;	// 10
	};
	static_assert(sizeof(ExtraInfoGeneralTopic) == 0x18);
}
