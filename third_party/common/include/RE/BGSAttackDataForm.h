#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BGSAttackDataMap;


	class BGSAttackDataForm : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSAttackDataForm;


		virtual ~BGSAttackDataForm();										// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01 - { return; }
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		NiPointer<BGSAttackDataMap> attackDataMap;	// 08
	};
	static_assert(sizeof(BGSAttackDataForm) == 0x10);
}
