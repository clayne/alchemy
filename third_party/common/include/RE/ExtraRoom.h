#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiRefObject;


	class ExtraRoom : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRoom;


		enum { kExtraTypeID = ExtraDataType::kRoom };


		virtual ~ExtraRoom();							// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kRoom; }


		// members
		NiPointer<NiRefObject> unk10;	// 10
	};
	static_assert(sizeof(ExtraRoom) == 0x18);
}
