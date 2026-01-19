

namespace mystd {
	template <typename T>
	class unique_ptr {
	public:
		unique_ptr(T* ptr = nullptr) : m_ptr {ptr}
		{}

		~unique_ptr() {	delete m_ptr; }

		unique_ptr(unique_ptr) = delete;
		operator=(unique_ptr) = delete;

		unique_ptr(unique_ptr&& other) : unique_ptr {} {
			swap(*this, other);
		}

		unique_ptr& operator=(unique_ptr&& other) {
			if (this != &other) {
				delete m_ptr;
				m_ptr = other.m_ptr;
				other.m_ptr = nullptr;
			}

			return *this;
		}

		friend swap(unique_ptr& left, unique_ptr& right) {
			using std::swap; // enable ADL
			swap(left.m_ptr, right.m_ptr);
		}


	private:
		T* m_ptr {};
	};
}
