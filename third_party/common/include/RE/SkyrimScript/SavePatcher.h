#pragma once


namespace RE
{
	namespace SkyrimScript
	{
		class SavePatcher
		{
		public:
			inline static const void* RTTI = RTTI_SkyrimScript__SavePatcher;


			virtual ~SavePatcher();	// 00
		};
		static_assert(sizeof(SavePatcher) == 0x8);
	}
}
