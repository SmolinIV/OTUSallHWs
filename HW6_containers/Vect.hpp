#pragma once
#include "Interface.hpp"


template <typename T>
class Row : public Interface_Containers<T, N> {

private:
	T* v_arr;
	std::size_t v_size;
	std::size_t v_capacity;
	int v_last;
	const float v_koef = 2.0f;

public:
	Row();

	Row(std::initializer_list<T> list);

	std::size_t capacity() const { return v_capacity; }

	std::size_t size() const override { return v_size; }

	T& operator[](unsigned int index) const override { return v_arr[index]; }

	void push_back(const T& value) override;

	void increase_capacity();

	void insert(unsigned int index, const T& value) override;

	void erase(unsigned int index) override;

	~Row() {
		delete[] v_arr;
		v_arr = nullptr;
		std::cout << "Class was destructed." << std::endl;

	}

	//Для тестирования
	void print() {
		for (int i = 0; i < v_size; i++) {
			std::cout << v_arr[i] << "   ";
		}
		std::cout << "\n\n";
	}
};

#include "Vect.inl"

