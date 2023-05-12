#pragma once
#include "Interface.hpp"


template <typename T, std::size_t N>
class Vect : public Interface_Containers<T, N> {

private:
	T* v_arr;
	std::size_t v_size;
	std::size_t v_capacity;
	int v_last;
	const float v_koef = 2.0f;

public:
	Vect() {
		v_size = N;
		v_capacity = N * v_koef;
		v_arr = new T[v_capacity];
		v_last = 0;
	}

	Vect(T value, ...) {
		v_size = N;
		v_capacity = N * v_koef;
		v_arr = new T[v_capacity];
		v_arr[0] = value;
		v_last = 1;
	}


	void printArr() {
		for (int i = 0; i < v_size; i++) {
			std::cout << v_arr[i] << '\t';
		}
		std::cout << std::endl;
	}

	std::size_t size() const override { return v_size; }
	std::size_t capacity() const override { return v_capacity; }

	void push_back(T value) override;

	void resize();

	~Vect() {
		delete[] v_arr;
		v_arr = nullptr;
		std::cout << "Class was destructed." << std::endl;
	}

	T& operator[](int index) {

		//if (index < 0 || index != v_size) {
		//	return (T)(-1); // Пока не придумал, как обработать эту ситуацию
		//}

		return v_arr[index];

	}
};

#include "Vect.inl" /////////////////////////////////////////////////

template <typename T, std::size_t N>
void Vect<T, N>::resize() {
	v_capacity *= v_koef;
	T* temp_arr = new T[v_capacity];

	for (int i = 0; i < v_size; i++) {
		temp_arr[i] = v_arr[i];
	}

	v_arr = temp_arr;
	temp_arr = nullptr;
}

template <typename T, std::size_t N>
void Vect<T, N>::push_back(T value) {
	if (v_last < v_capacity) {
		v_arr[v_last] = value;

		if (v_last == v_size) {
			++v_size;
		}
		++v_last;
	}
	else {
		this->resize();
		this->push_back(value);
	}
}

//template <typename T, std::size_t N>
//T &operator[](int index) 
