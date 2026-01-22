namespace mystd {
	template <typename T>
	struct remove_reference { using type = T; }

	template <typename T&>
	struct remove_reference { using type = T; }

	template <typename T&&>
	struct remove_reference { using type = T; }

	template <typename T>
	using remove_reference_t = typename remove_reference<T>::type;
}
