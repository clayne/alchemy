#pragma once

#include "RE/hkpBroadPhaseHandle.h"


namespace RE
{
	class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
	{
		enum { kInvalidOffset = 127 };


		SInt8	type;					// 4
		SInt8	ownerOffset;			// 5
		SInt8	objectQualityType;		// 6
		SInt8	pad7;					// 7
		UInt32	collisionFilterInfo;	// 8
	};
	static_assert(sizeof(hkpTypedBroadPhaseHandle) == 0xC);
}
