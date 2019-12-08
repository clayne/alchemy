#pragma once

#include "RE/IMessageBoxCallback.h"


namespace RE
{
	class OldMessageBoxCallback : public IMessageBoxCallback
	{
	public:
		using Callback = void(Message);


		virtual ~OldMessageBoxCallback();			// 00

		// override (IMessageBoxCallback)
		virtual void Run(Message a_msg) override;	// 01


		// members
		Callback* callback;	// 10
	};
	static_assert(sizeof(OldMessageBoxCallback) == 0x18);
}
