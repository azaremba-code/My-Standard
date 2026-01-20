class unique_ptr;

namespace mystd {
	template <typename T>
	constexpr void swap(T& a, T& b) {
		T c = a;
		a = b;
		b = c;
	}

	template <>
	constexpr void swap(unique_ptr& a, unique_ptr& b) {
		a.swap(b);
	}
}
