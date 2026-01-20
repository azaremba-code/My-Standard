namespace mystd {
	template <typename T>
	constexpr void swap(T& a, T& b) {
		T c = a;
		a = b;
		b = c;
	}
}
