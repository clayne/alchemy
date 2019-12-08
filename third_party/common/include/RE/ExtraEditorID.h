#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSFixedString.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraEditorID : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEditorID;


		enum { kExtraTypeID = ExtraDataType::kEditorID };


		virtual ~ExtraEditorID();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kEditorID; }


		// members
		BSFixedString editorID;	// 10
	};
	static_assert(sizeof(ExtraEditorID) == 0x18);
}
