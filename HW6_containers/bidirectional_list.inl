#include "bidirectional_list.hpp"

#define TEMPL_CONT template <typename T>

//Конструктор по умолчанию
TEMPL_CONT
Bidirectional_list<T>::Bidirectional_list() {
	element = new Cell;
	element->lhs = nullptr;
	element->rhs = nullptr;
	bd_first = element;
	bd_last = element;
	bd_size = 0;
}

// Конструктор с параметрами
TEMPL_CONT
Bidirectional_list<T>::Bidirectional_list(std::initializer_list<T> list) : Bidirectional_list() {
	for (auto i : list) {
		push_back(i);
	}
}

// Добавление нового элемента в конец списка
TEMPL_CONT
void Bidirectional_list<T>::push_back(const T& value) {
	if (bd_size == 0) {
		bd_last->value = value;

	}
	else {
		Cell* temp = new Cell;
		temp->lhs = bd_last;
		bd_last->rhs = temp;
		temp->value = value;
		temp->rhs = nullptr;
		bd_last = temp;
		temp = nullptr;
	}
	++bd_size;
}

TEMPL_CONT
T& Bidirectional_list<T>::operator[](unsigned int index) const {
	Cell* temp;
	if (index <= bd_size / 2) {
		temp = bd_first;
		for (int i = 0; i < index; i++) {
			temp = temp->rhs;
		}
	} 
	else {
		temp = bd_last;
		for (int i = bd_size - 1; i > index; i--) {
			temp = temp->lhs;
		}
	}
	return temp->value;
}