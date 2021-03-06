#pragma once

#include "RE/hkReferencedObject.h"
#include "RE/hkpCharacterState.h"


namespace RE
{
	class hkpCharacterStateManager : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkpCharacterStateManager;


		virtual ~hkpCharacterStateManager();	// 00


		// members
		hkpCharacterState* registeredState[hkpCharacterStateType::kTotal];	// 00
	};
	static_assert(sizeof(hkpCharacterStateManager) == 0x68);
}
