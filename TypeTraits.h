#ifndef TYPE_TRAITS_H
#define TYPE_TRIATS_H

namespace mystd {
	template <typename T>
	struct remove_reference { using type = T; };

	template <typename T>
	struct remove_reference<T&> { using type = T; };

	template <typename T>
	struct remove_reference<T&&> { using type = T; };

	template <typename T>
	using remove_reference_t = typename remove_reference<T>::type;
}

#endif
