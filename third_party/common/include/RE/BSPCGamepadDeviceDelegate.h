#pragma once

#include "RE/BSGamepadDevice.h"


namespace RE
{
	class BSPCGamepadDeviceDelegate : public BSGamepadDevice
	{
	public:
		inline static const void* RTTI = RTTI_BSPCGamepadDeviceDelegate;


		virtual ~BSPCGamepadDeviceDelegate();			// 00

		// override (BSGamepadDevice)
		virtual void	Initialize() override;			// 01 - { return; }
		virtual	void	Process(float a_arg1) override;	// 02 - { return; }
		virtual	void	Unk_03(void) override;			// 03 - { return; }
		virtual void	Reset() override;				// 08 - { return; }
		virtual void	Unk_09(void) override;			// 09 - { return; }


		// members
		UInt64 unkD0;	// D0
	};
	static_assert(sizeof(BSPCGamepadDeviceDelegate) == 0xD8);
}
