#include "TypeTraits.h"

class unique_ptr;

namespace mystd {
	template <typename T>
	mystd::remove_reference_t<T>&& move(T&& x) {
		return static_cast<mystd::remove_reference<T>&&>(x);
	}

	template <typename T>
	constexpr void swap(T& a, T& b) {
		T&& c = mystd::move(a);
		a = mystd::move(b);
		b = mystd::move(c);
	}

	template <>
	constexpr void swap(unique_ptr& a, unique_ptr& b) {
		a.swap(b);
	}
}
