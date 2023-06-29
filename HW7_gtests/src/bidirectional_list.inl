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


// Поиск ячейки по заданному индексу.
TEMPL_CONT
void Bidirectional_list<T>::search_cell(unsigned int index) {
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
}



// Добавление нового элемента в конец списка
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

//Перегрузка оператора индексорвания для возврата знчения ячейки (с выбором более короткого пути нахождения - старт с начала или с конца)
TEMPL_CONT
T& Bidirectional_list<T>::operator[](unsigned int index) {
	search_cell(index);
	return bd_temp->value;
}

// Вставка элеманта по указанному индексу
TEMPL_CONT
void Bidirectional_list<T>::insert(unsigned int index, const T& value) {
	Cell* previos_cell;
	Cell* new_cell = new Cell;
	new_cell->value = value;

	if (index == 0) {
		new_cell->lhs = nullptr;
		new_cell->rhs = bd_first;
		bd_first->lhs = new_cell;
		bd_first = new_cell;
	}
	else {
		if (index != bd_size - 1) {
			search_cell(index);
		}
		else {
			bd_temp = bd_last;
		}
		previos_cell = bd_temp->lhs;
		previos_cell->rhs = new_cell;
		bd_temp->lhs = new_cell;
		new_cell->lhs = previos_cell;
		new_cell->rhs = bd_temp;

	}

	previos_cell = nullptr;	// Память выделена, ячейки связаны,
	new_cell = nullptr;		// поэтому оба указателя зануляются.
	
	++bd_size;
}

// Удаление элемента по указанному индексу
TEMPL_CONT
void Bidirectional_list<T>::erase(unsigned int index) {
	if (index == 0) {
		bd_first = bd_temp->rhs;
		bd_temp->rhs = nullptr;
		bd_first->lhs = nullptr;
	}
	else if (index == bd_size - 1) {
		bd_last = bd_temp->lhs;
		bd_temp->lhs = nullptr;
		bd_last->rhs = nullptr;
	}
	else {
		search_cell(index);
		Cell* previos_cell = bd_temp->lhs;
		previos_cell->rhs = bd_temp->rhs;
		previos_cell = bd_temp->rhs;
		previos_cell->lhs = bd_temp->lhs;
	}
		bd_temp->lhs = nullptr;
		bd_temp->rhs = nullptr;
		delete bd_temp;
		bd_temp = nullptr;

	--bd_size;
}

// Удобный вывод массива на экран
TEMPL_CONT
void Bidirectional_list<T>::print_list() {
	bd_temp = bd_first;
	while (bd_temp) {
		std::cout << bd_temp->value << "  ";
		bd_temp = bd_temp->rhs;
	}
	std::cout << "\n\n";
}