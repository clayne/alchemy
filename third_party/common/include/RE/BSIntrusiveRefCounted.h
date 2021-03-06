#pragma once

#include "RE/TESMemoryManager.h"


namespace RE
{
	struct BSIntrusiveRefCounted
	{
	public:
		template <class T> friend struct BSTSmartPointerIntrusiveRefCount;


		BSIntrusiveRefCounted();

		SInt32	IncRefCount();
		SInt32	DecRefCount();

		TES_HEAP_REDEFINE_NEW();


		// members
		volatile SInt32 _refCount;	// 0
	};
	static_assert(sizeof(BSIntrusiveRefCounted) == 0x4);
}
