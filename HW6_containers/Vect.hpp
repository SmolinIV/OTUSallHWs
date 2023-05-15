#pragma once
#include "Interface.hpp"


template <typename T>
class Row : public Interface_Containers<T> {

private:
	T* r_arr;
	std::size_t r_size;
	std::size_t r_capacity;
	int r_last;
	const int r_koef = 2;

	Iterator<T> r_iter;

public:

	Row();

	Row(std::initializer_list<T> list);

	std::size_t capacity() const { return r_capacity; }

	std::size_t size() const override { return r_size; }

	T& operator[](unsigned int index) const override { return r_arr[index]; }

	void push_back(const T& value) override;

	void increase_capacity();

	void insert(unsigned int index, const T& value) override;

	void erase(unsigned int index) override;

	Iterator<T> begin();

	~Row() {
		delete[] r_arr;
		r_arr = nullptr;
		std::cout << "Class was destructed." << std::endl;
	}

	//Для тестирования
	void print() const;
};

#include "Vect.inl"







template <typename T>
void Row<T>::print() const
{
	for (int i = 0; i < r_size; i++) {
		std::cout << r_arr[i] << "   ";
	}
	std::cout << "\n\n";
}


