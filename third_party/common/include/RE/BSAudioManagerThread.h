#pragma once

#include "RE/BSThread.h"


namespace RE
{
	class BSAudioManagerThread : public BSThread
	{
	public:
		inline static const void* RTTI = RTTI_BSAudioManagerThread;


		virtual ~BSAudioManagerThread();	// 00

		// override (BSThread)
		virtual void Unk_01(void) override;	// 01


		// members
		UInt64	unk50;	// 50
		UInt64	unk58;	// 58
		UInt64	unk60;	// 60
	};
	static_assert(sizeof(BSAudioManagerThread) == 0x68);
}
