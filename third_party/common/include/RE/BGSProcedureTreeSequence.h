#pragma once

#include "RE/BGSProcedureTreeBranch.h"
#include "RE/BGSTypedItem.h"


namespace RE
{
	class BGSProcedureTreeSequence : public BGSTypedItem<BGSProcedureTreeSequence, BGSProcedureTreeBranch>
	{
	public:
		inline static const void* RTTI = RTTI_BGSProcedureTreeSequence;


		virtual ~BGSProcedureTreeSequence();	// 00

		// override (BGSProcedureTreeBranch)
		virtual void	Unk_04(void) override;	// 04
		virtual void	Unk_06(void) override;	// 06
	};
	static_assert(sizeof(BGSProcedureTreeSequence) == 0x30);
}
