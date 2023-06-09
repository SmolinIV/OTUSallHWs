template <typename T>
struct Iterator {
	T* i_pointer;

	Iterator() : i_pointer{ nullptr } {}

	Iterator(T& link) : i_pointer{ link } {}

	Iterator& operator=(T* link) {
		this->i_pointer = link;
		return *this;
	}


	friend std::ostream& operator<<(std::ostream& out, Iterator<T>& value) {
		out << value.i_pointer;
		return out;
	}

	T& operator*() {
		return *i_pointer;
	}

	friend T* operator+(Iterator& it1, int step) {
		return it1.i_pointer + step;
	}

	friend T* operator-(Iterator& it1, int step) {
		return it1.i_pointer - step;
	}

	friend bool operator!=(const Iterator& i1, const Iterator& i2) {
		return i1.i_pointer != i2.i_pointer;
	}

	T* operator++() {
		return ++i_pointer;
	}

	T* operator--() {
		return --i_pointer;
	}
};