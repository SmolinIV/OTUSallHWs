#pragma once
#include "Interface.hpp"

template <typename T>
class Unidirectional_list : Interface_Containers<T> {
private:
	struct Cell {
		T value;
		Cell* rhs;
	} *element;

	std::size_t ud_size;

	Cell* ud_first;
	Cell* ud_last;
	Cell* ud_temp; //Указатель для временного хранения. Создан здесь, чтобы не оставить незанулённых указателей. Зануляется в дистркуторе.

	void search_cell(unsigned int index);
public:

	Unidirectional_list();

	Unidirectional_list(std::initializer_list<T> list);

	std::size_t size() const override { return ud_size; };

	void push_back(const T& value) override;

	T& operator[](unsigned int index) override;

	void insert(unsigned int index, const T& value) override;

	void erase(unsigned int index) override;

	void print_list();

	~Unidirectional_list() {
		while (ud_first) {
			ud_temp = ud_first->rhs;
			ud_first->rhs = nullptr;
			delete ud_first;
			ud_first = ud_temp;
		}
		element = nullptr;
		ud_first = nullptr;
		ud_last = nullptr;
		ud_temp = nullptr;
		std::cout << "All cells of UD-List are destructed." << std::endl;
	}
};


#include "unidirectional_list.inl"