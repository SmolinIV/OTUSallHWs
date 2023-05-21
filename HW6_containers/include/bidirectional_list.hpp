#pragma once
#include "Interface.hpp"

template <typename T> 
class Bidirectional_list : public Interface_Containers<T> {
private:
	struct Cell {
		Cell* lhs;
		T value;
		Cell* rhs;
	} *element;

	std::size_t bd_size;

	Cell* bd_first;
	Cell* bd_last;
	Cell* bd_temp; //Указатель для временного хранения. Создан здесь, чтобы не оставить незанулённых указателей. Зануляется в дистркуторе.

	void search_cell(unsigned int index);
public:

	Bidirectional_list();

	Bidirectional_list(std::initializer_list<T> list);
	
	std::size_t size() const override { return bd_size; };

	void push_back(const T& value) override;

	T& operator[](unsigned int index) override;

	void insert(unsigned int index, const T& value) override;

	void erase(unsigned int index) override;

	void print_list();

	~Bidirectional_list() {
		while (bd_first) {
			delete bd_first->lhs;
			bd_first->lhs = nullptr;
			bd_first = bd_first->rhs;
		}
		element = nullptr;
		bd_first = nullptr;
		bd_last = nullptr;
		bd_temp = nullptr;
		std::cout << "All cells are destructed." << std::endl;
	}
};

#include "bidirectional_list.inl"
