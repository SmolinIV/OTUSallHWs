#pragma once
#include <iostream>


template <typename T>
class Interface_Containers {
public:
	virtual ~Interface_Containers() {}

	virtual std::size_t size() const = 0;

	virtual void push_back(const T& value) = 0;

	virtual T& operator[](unsigned int index) const = 0;

	virtual void insert(unsigned int index, const T& value) = 0;

	virtual void erase(unsigned int index) = 0;

	//virtual Iterator<T> begin() = 0;
	//virtual T* end() const = 0;

};

template <typename T>
class Iterator {
public:
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
};