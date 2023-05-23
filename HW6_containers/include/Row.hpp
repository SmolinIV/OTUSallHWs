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
	void increase_capacity();

public:

	Row();
	explicit Row(Row&& other);
	explicit Row(const Row& other);
	Row(std::initializer_list<T> list);

	std::size_t capacity() const { return r_capacity; }

	std::size_t size() const override { return r_size; }

	T& operator[](unsigned int index) override { return r_arr[index]; }

	void push_back(const T& value) override;


	void insert(unsigned int index, const T& value) override;

	void erase(unsigned int index) override;

	void shrink_to_fit();

	Iterator<T> begin();
	Iterator<T> end();

	~Row() {
		delete[] r_arr;
		r_arr = nullptr;
		std::cout << "Class was destructed." << std::endl;
	}
};

#include "../src/Row.inl"

