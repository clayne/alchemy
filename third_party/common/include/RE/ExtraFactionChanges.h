#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"
#include "RE/FormTypes.h"


namespace RE
{
	class ExtraFactionChanges : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraFactionChanges;


		enum { kExtraTypeID = ExtraDataType::kFactionChanges };


		struct FactionInfo
		{
			TESFaction* faction;	// 00
			SInt8		rank;		// 08
			UInt8		pad9;		// 09
			UInt16		padA;		// 0A
			UInt32		padC;		// 0C
		};
		static_assert(sizeof(FactionInfo) == 0x10);


		virtual ~ExtraFactionChanges();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kFactionChanges; }


		// members
		BSTArray<FactionInfo>	factions;	// 10
		void*					unk28;		// 28
		UInt8					unk30;		// 30 - bool?
		UInt8					pad31;		// 31
		UInt16					pad32;		// 32
		UInt32					pad34;		// 34
	};
	static_assert(sizeof(ExtraFactionChanges) == 0x38);
}
