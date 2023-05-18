#pragma once
#include "Interface.hpp"

template <typename T>
class Bidirectional_list {
private:
	struct Cell {
		Cell* lhs;
		T value;
		Cell* rhs;
	} *element;

	std::size_t bd_size;

	Cell* bd_first;
	Cell* bd_last;
public:

	Bidirectional_list();

	Bidirectional_list(std::initializer_list<T> list);
	
	std::size_t size() const { return bd_size; };

	void push_back(const T& value);

	T& operator[](unsigned int index) const;

	//virtual void insert(unsigned int index, const T& value);

	//virtual void erase(unsigned int index);

	~Bidirectional_list() {
		while (!bd_first) {
			delete bd_first->lhs;
			bd_first = bd_first->rhs;
		}
		element = nullptr;
		std::cout << "All cells are destructed." << std::endl;
	}
};

#include "bidirectional_list.inl"
