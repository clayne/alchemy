#pragma once

#include "skse64_common/BranchTrampoline.h"

#include <array>
#include <cassert>
#include <string>
#include <string_view>
#include <vector>


namespace RE
{
	namespace RTTI
	{
		struct CompleteObjectLocator;
		struct TypeDescriptor;
	}
}


namespace REL
{
	namespace Impl
	{
		// msvc's safety checks increase debug builds' execution time by several orders of magnitude
		// so i've introduced this class to speed up debug builds which leverage exe scanning
		template <class T>
		class Array
		{
		public:
			using value_type = T;
			using size_type = std::size_t;
			using reference = value_type&;
			using const_reference = const value_type&;
			using pointer = value_type*;


			Array() = delete;


			Array(size_type a_size) :
				_data(0),
				_size(a_size),
				_owned(true)
			{
				_data = new value_type[_size];
			}


			Array(pointer a_data, size_type a_size) :
				_data(a_data),
				_size(a_size),
				_owned(false)
			{}


			Array(const std::vector<value_type>& a_vec) :
				_data(0),
				_size(0),
				_owned(true)
			{
				_size = a_vec.size();
				_data = new value_type[_size];
				for (size_type i = 0; i < _size; ++i) {
					_data[i] = a_vec[i];
				}
			}


			~Array()
			{
				if (_owned) {
					delete[] _data;
				}
			}


			reference operator[](size_type a_pos)
			{
				return _data[a_pos];
			}


			const_reference operator[](size_type a_pos) const
			{
				return _data[a_pos];
			}


			size_type size() const
			{
				return _size;
			}

		private:
			pointer _data;
			size_type _size;
			bool _owned;
		};


		// https://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
		constexpr auto NPOS = static_cast<std::size_t>(-1);

		void kmp_table(const Array<std::uint8_t>& W, Array<std::size_t>& T);
		void kmp_table(const Array<std::uint8_t>& W, const Array<bool>& M, Array<std::size_t>& T);

		std::size_t kmp_search(const Array<std::uint8_t>& S, const Array<std::uint8_t>& W);
		std::size_t kmp_search(const Array<std::uint8_t>& S, const Array<std::uint8_t>& W, const Array<bool>& M);
	}


	class Module
	{
	public:
		struct IDs
		{
			enum ID
			{
				kTextX,
				kIData,
				kRData,
				kData,
				kPData,
				kTLS,
				kTextW,
				kGFIDs,

				kTotal
			};
		};
		using ID = IDs::ID;


		class Section
		{
		public:
			constexpr Section() :
				addr(0xDEADBEEF),
				size(0xDEADBEEF),
				rva(0xDEADBEEF)
			{}


			std::uint32_t RVA() const;
			std::uintptr_t BaseAddr() const;
			std::size_t Size() const;


			template <class T = void>
			inline T* BasePtr() const
			{
				return reinterpret_cast<T*>(BaseAddr());
			}

		protected:
			friend class Module;


			std::uintptr_t addr;
			std::size_t size;
			std::uint32_t rva;
		};


		static std::uintptr_t BaseAddr();
		static std::size_t Size();
		static Section GetSection(ID a_id);


		template <class T = void>
		inline static T* BasePtr()
		{
			return reinterpret_cast<T*>(_info.base);
		}

	private:
		struct ModuleInfo
		{
			struct Sections
			{
				struct Elem
				{
					constexpr Elem(std::string_view a_view, UInt32 a_flags = 0) :
						name(a_view),
						section(),
						flags(a_flags)
					{}


					std::string_view name;
					Section	section;
					UInt32 flags;
				};


				constexpr Sections() :
					arr{ Elem(".text", IMAGE_SCN_MEM_EXECUTE), ".idata", ".rdata", ".data", ".pdata", ".tls", Elem(".text", IMAGE_SCN_MEM_WRITE), ".gfids" }
				{}


				std::array<Elem, ID::kTotal> arr;
			};


			ModuleInfo();


			std::uintptr_t base;
			std::size_t size;
			Sections sections;
		};


		static ModuleInfo _info;
	};


	template <class T>
	class Offset
	{
	public:
		Offset() = delete;


		Offset(std::uintptr_t a_offset) :
			_address(Module::BaseAddr() + a_offset)
		{}


		template <class U = T, typename std::enable_if_t<std::is_pointer<U>::value, int> = 0>
		std::add_lvalue_reference_t<std::remove_pointer_t<U>> operator*() const
		{
			return *GetType();
		}


		template <class U = T, typename std::enable_if_t<std::is_pointer<U>::value, int> = 0>
		U operator->() const
		{
			return GetType();
		}


		template <class... Args, class U = std::decay_t<T>, typename std::enable_if_t<std::is_invocable<U, Args...>::value, int> = 0>
		std::invoke_result_t<U, Args...> operator()(Args&&... a_args) const
		{
			return GetType()(std::forward<Args>(a_args)...);
		}


		T GetType() const
		{
			return unrestricted_cast<T>(GetAddress());
		}


		std::uintptr_t GetAddress() const
		{
			return _address;
		}


		std::uintptr_t GetOffset() const
		{
			return GetAddress() - Module::BaseAddr();
		}

	private:
		std::uintptr_t _address;
	};


	// pattern scans exe for given sig
	// sig must be an ida pattern, and must be unique (first found match is returned)
	template <class T>
	class DirectSig
	{
	public:
		DirectSig() = delete;


		DirectSig(const char* a_sig) :
			_address(0xDEADBEEF)
		{
			std::vector<std::uint8_t> sig;
			std::vector<bool> mask;
			std::string buf;
			buf.resize(2);
			for (std::size_t i = 0; a_sig[i] != '\0';) {
				switch (a_sig[i]) {
				case ' ':
					++i;
					break;
				case '?':
					mask.push_back(false);
					sig.push_back(0x00);
					do {
						++i;
					} while (a_sig[i] == '?');
					break;
				default:
					mask.push_back(true);
					buf[0] = a_sig[i++];
					buf[1] = a_sig[i++];
					sig.push_back(static_cast<std::uint8_t>(std::stoi(buf, 0, 16)));
					break;
				}
			}

			auto text = Module::GetSection(Module::ID::kTextX);
			Impl::Array<std::uint8_t> haystack(text.BasePtr<std::uint8_t>(), text.Size());
			Impl::Array<std::uint8_t> needle(sig.data(), sig.size());
			Impl::Array<bool> needleMask(mask);
			_address = Impl::kmp_search(haystack, needle, needleMask);

			if (_address == 0xDEADBEEF) {
				LOG_FATALERROR("Sig scan failed for pattern (%s)!\n", a_sig);
				assert(false);
			} else {
				_address += text.BaseAddr();
			}
		}


		operator T() const
		{
			return unrestricted_cast<T>(GetAddress());
		}


		T GetType() const
		{
			return unrestricted_cast<T>(GetAddress());
		}


		std::uintptr_t GetAddress() const
		{
			assert(_address != 0xDEADBEEF);
			return _address;
		}


		std::uintptr_t GetOffset() const
		{
			return GetAddress() - Module::BaseAddr();
		}

	protected:
		mutable std::uintptr_t _address;
	};


	// pattern scans exe for given sig, reads offset from first opcode, and calculates effective address from next op code
	template <class T>
	class IndirectSig : public DirectSig<T>
	{
	public:
		IndirectSig() = delete;


		IndirectSig(const char* a_sig) :
			DirectSig<T>(a_sig)
		{
			auto offset = reinterpret_cast<std::int32_t*>(_address + 1);
			auto nextOp = _address + 5;
			_address = nextOp + *offset;
		}
	};


	// scans exe for type descriptor name, then retrieves vtbl address at specified offset
	class VTable
	{
	public:
		VTable() = delete;
		VTable(const char* a_name, std::uint32_t a_offset = 0);

		void* GetPtr() const;
		std::uintptr_t GetAddress() const;
		std::uintptr_t GetOffset() const;

	private:
		using ID = Module::ID;


		RE::RTTI::TypeDescriptor* LocateTypeDescriptor(const char* a_name) const;
		RE::RTTI::CompleteObjectLocator* LocateCOL(RE::RTTI::TypeDescriptor* a_typeDesc, std::uint32_t a_offset) const;
		void* LocateVtbl(RE::RTTI::CompleteObjectLocator* a_col) const;


		std::uintptr_t _address;
	};


	template <class F = void*>
	F Write5Call(std::uintptr_t a_dst, std::uintptr_t a_src)
	{
		auto offset = reinterpret_cast<std::int32_t*>(a_dst + 1);
		auto nextOp = a_dst + 5;
		auto func = unrestricted_cast<F>(nextOp + *offset);
		g_branchTrampoline.Write5Call(a_dst, a_src);
		return func;
	}
}
