#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include "Utility.h"

namespace mystd {
	template <typename T>
	class unique_ptr {
	public:
		using pointer = T*;
		using element_type = T;

		unique_ptr(T* ptr = nullptr) : m_ptr {ptr}
		{}

		~unique_ptr() {	delete m_ptr; }

		unique_ptr(const unique_ptr&) = delete;
		void operator=(const unique_ptr&) = delete;

		unique_ptr(unique_ptr&& other) : m_ptr {other.m_ptr} {
			other.m_ptr = nullptr;	
		}

		unique_ptr& operator=(unique_ptr&& other) {
			if (this != &other) {
				delete m_ptr;
				m_ptr = other.m_ptr;
				other.m_ptr = nullptr;
			}

			return *this;
		}

		
		pointer release() noexcept {
			T* copy {m_ptr};
			m_ptr = nullptr;
			return copy;
		}	

		void reset() noexcept {
			delete m_ptr; // deleting nullptr is noop
			m_ptr = nullptr;
		}

		void swap(unique_ptr& other) noexcept {
			mystd::swap(m_ptr, other.m_ptr);
		}


		
		pointer get() const noexcept {
			return m_ptr;
		}

		operator bool() const noexcept {
			return m_ptr != nullptr;
		}

		
		//TODO: change return type to mystd::add_lvalue_reference_t<T> to all allow for T = void
		element_type& operator*() const {
			return *m_ptr;
		}

		pointer operator->() const noexcept {
			return m_ptr;
		}

	private:
		T* m_ptr {};
	};

	//TODO: implement make_unique once we write mystd::forward
	
	template <typename T>
	bool operator==(const unique_ptr<T>& lhs, const unique_ptr<T>& rhs) {
		return lhs.get() == rhs.get();
	}

	//TODO: implement support for mystd::nullptr_t comparisons, and the rest of comparison operators
}

#endif
