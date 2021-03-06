#pragma once

#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESIcon.h"


namespace RE
{
	class BGSMenuIcon :
		public TESForm,	// 00
		public TESIcon	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSMenuIcon;


		enum { kTypeID = FormType::MenuIcon };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~BGSMenuIcon();							// 00

		// override (TESForm)
		virtual bool LoadForm(TESFile* a_mod) override;	// 06 - { return true; }
	};
	static_assert(sizeof(BGSMenuIcon) == 0x30);
}
