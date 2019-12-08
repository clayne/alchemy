#pragma once

#include "RE/GRefCountBase.h"
#include "RE/GStats.h"


namespace RE
{
	class FxDelegateArgs;
	class GString;


	class FxDelegateHandler : public GRefCountBase<FxDelegateHandler, GStatGroups::kGStat_Default_Mem>
	{
	public:
		inline static const void* RTTI = RTTI_FxDelegateHandler;


		using CallbackFn = void(const FxDelegateArgs& a_params);


		class CallbackProcessor
		{
		public:
			inline static const void* RTTI = RTTI_FxDelegateHandler__CallbackProcessor;


			virtual ~CallbackProcessor() = default;											// 00

			// add
			virtual void Process(const GString& a_methodName, CallbackFn* a_method) = 0;	// 01
		};
		static_assert(sizeof(CallbackProcessor) == 0x8);


		virtual ~FxDelegateHandler() = default;					// 00

		// add
		virtual void Accept(CallbackProcessor* a_cbReg) = 0;	// 01
	};
	static_assert(sizeof(FxDelegateHandler) == 0x10);
}
