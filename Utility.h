#include "TypeTraits.h"

namespace mystd {
	template <typename T>
	class unique_ptr;

	template <typename T>
	mystd::remove_reference_t<T>&& move(T&& x); 

	template <typename T>
	constexpr void swap(T& a, T& b);

	template <typename T>
	constexpr void swap(mystd::unique_ptr<T>& a, mystd::unique_ptr<T>& b);
}

#include "Utility.tpp"
