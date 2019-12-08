#pragma once

#include "RE/BSString.h"
#include "RE/BSTArray.h"
#include "RE/BSTSmartPointer.h"
#include "RE/IUIMessageData.h"


namespace RE
{
	class IMessageBoxCallback;


	class MessageBoxData : public IUIMessageData
	{
	public:
		inline static const void* RTTI = RTTI_MessageBoxData;


		virtual ~MessageBoxData();	// 00


		// members
		BSString								message;	// 10
		BSTArray<BSString>						options;	// 20
		UInt32									unk38;		// 38
		SInt32									unk3C;		// 3C
		BSTSmartPointer<IMessageBoxCallback>	callback;	// 40
		UInt32									unk48;		// 48
		UInt8									unk4C;		// 4C
		UInt8									unk4D;		// 4D
		UInt8									unk4E;		// 4E
		UInt8									unk4F;		// 4F
	};
	static_assert(sizeof(MessageBoxData) == 0x50);
}
