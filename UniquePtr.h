#include "Utility.h"

namespace mystd {
	template <typename T>
	class unique_ptr {
	public:
		unique_ptr(T* ptr = nullptr) : m_ptr {ptr}
		{}

		~unique_ptr() {	delete m_ptr; }

		unique_ptr(unique_ptr) = delete;
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

		void reset() noexcept {
			delete m_ptr; // deleting nullptr is noop
			m_ptr = nullptr;
		}

		void swap(unique_ptr& other) noexcept {
			mystd::swap(m_ptr, other.m_ptr);
		}

	private:
		T* m_ptr {};
	};
}
