#include "bidirectional_list.hpp"

#define TEMPL_CONT template <typename T>

// онструктор по умолчанию
TEMPL_CONT
Bidirectional_list<T>::Bidirectional_list() {
	element = new Cell;
	element->lhs = nullptr;
	element->rhs = nullptr;
	bd_first = element;
	bd_last = element;
	bd_size = 0;
}

//  онструктор с параметрами
TEMPL_CONT
Bidirectional_list<T>::Bidirectional_list(std::initializer_list<T> list) : Bidirectional_list() {
	for (auto i : list) {
		push_back(i);
	}
}

// ƒобавление нового элемента в конец списка
TEMPL_CONT
void Bidirectional_list<T>::push_back(const T& value) {
	if (bd_size == 0) {
		bd_last->value = value;
	}
	else {
		bd_temp = new Cell;
		bd_temp->lhs = bd_last;
		bd_last->rhs = bd_temp;
		bd_temp->value = value;
		bd_temp->rhs = nullptr;
		bd_last = bd_temp;
		bd_temp = nullptr;
	}
	++bd_size;
}

//ѕерегрузка оператора индексорвани€ дл€ возврата знчени€ €чейки (с выбором более короткого пути нахождени€ - старт с начала или с конца)
TEMPL_CONT
T& Bidirectional_list<T>::operator[](unsigned int index) {
	//Cell* temp;
	if (index <= bd_size / 2) {
		bd_temp = bd_first;
		for (int i = 0; i < index; i++) {
			bd_temp = bd_temp->rhs;
		}
	} 
	else {
		bd_temp = bd_last;
		for (int i = bd_size - 1; i > index; i--) {
			bd_temp = bd_temp->lhs;
		}
	}
	return bd_temp->value;
}

TEMPL_CONT
void Bidirectional_list<T>::insert(unsigned int index, const T& value) {

}