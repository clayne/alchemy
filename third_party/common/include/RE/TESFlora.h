#pragma once

#include "RE/FormTypes.h"
#include "RE/TESObjectACTI.h"
#include "RE/TESProduceForm.h"


namespace RE
{
	class TESFlora :
		public TESObjectACTI,	// 00
		public TESProduceForm	// C8
	{
	public:
		inline static const void* RTTI = RTTI_TESFlora;


		enum { kTypeID = FormType::Flora };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESFlora();																																		// 00

		// override (TESObjectACTI)
		virtual bool	LoadForm(TESFile* a_mod) override;																											// 06
		virtual void	InitItem() override;																														// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																			// 4C
		virtual void	Unk_4D(void) override;																														// 4D
	};
	static_assert(sizeof(TESFlora) == 0xE8);
}
