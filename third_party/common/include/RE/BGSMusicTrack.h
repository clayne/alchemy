#pragma once

#include "RE/BSIMusicTrack.h"
#include "RE/Condition.h"


namespace RE
{
	class TESFile;


	class BGSMusicTrack : public BSIMusicTrack
	{
	public:
		inline static const void* RTTI = RTTI_BGSMusicTrack;


		virtual ~BGSMusicTrack();						// 00

		// override (BSIMusicTrack)
		virtual bool	CanPlay(void) override;			// 07 - { return conditions ? conditions->Run(g_thePlayer, g_thePlayer) : true; }

		// add
		virtual bool	InitTrack(TESFile* a_mod);		// 0B
		virtual bool	LoadTrack(TESFile* a_mod) = 0;	// 0C


		// members
		Condition	conditions;	// 10
		UInt64		unk18;		// 18
	};
	static_assert(sizeof(BGSMusicTrack) == 0x20);
}
