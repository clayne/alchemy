#pragma once

#include "RE/TESCamera.h"


namespace RE
{
	class RaceSexCamera : public TESCamera
	{
	public:
		inline static const void* RTTI = RTTI_RaceSexCamera;


		virtual ~RaceSexCamera();									// 00

		// override (TESCamera)
		virtual void	SetNode(NiPointer<NiNode> a_node) override;	// 01
		virtual void	Update() override;							// 02


		// members
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
		UInt64	unk48;	// 48
		UInt64	unk50;	// 50
	};
	static_assert(sizeof(RaceSexCamera) == 0x58);
}
