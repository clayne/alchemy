#pragma once

#include "RE/BGSPreloadable.h"
#include "RE/BSTHashMap.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSImpactDataSet :
		public TESForm,			// 00
		public BGSPreloadable	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSImpactDataSet;


		enum { kTypeID = FormType::ImpactDataSet };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSImpactDataSet();						// 00

		// override (TESForm)
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BSTHashMap<BGSMaterialType*, BGSImpactData*> data;	// 28 - PNAM
	};
	static_assert(sizeof(BGSImpactDataSet) == 0x58);
}
