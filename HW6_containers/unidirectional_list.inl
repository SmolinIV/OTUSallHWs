// Определение методов класса unidirectional_list
#define TEMPL_CONT template <typename T>


TEMPL_CONT
Unidirectional_list<T>::Unidirectional_list() {
	element = new Cell;
	element->rhs = nullptr;
	ud_first = element;
	ud_last = element;
	ud_size = 0;
}

// Конструктор с параметрами
TEMPL_CONT
Unidirectional_list<T>::Unidirectional_list(std::initializer_list<T> list) : Unidirectional_list() {
	for (auto i : list) {
		push_back(i);
	}
}


// Поиск ячейки по заданному индексу.
TEMPL_CONT
void Unidirectional_list<T>::search_cell(unsigned int index) {
	ud_temp = ud_first;
	for (int i = 0; i < index; i++) {
		ud_temp = ud_temp->rhs;
	}
}


TEMPL_CONT 
void Unidirectional_list<T>::push_back(const T& value) {
	if (ud_size == 0) {
		ud_last->value = value;
	}
	else {
		ud_temp = new Cell;
		ud_temp->value = value;
		ud_temp->rhs = nullptr;
		ud_last->rhs = ud_temp;
		ud_last = ud_temp;
		ud_temp = nullptr;
	}
	++ud_size;
}

TEMPL_CONT
T& Unidirectional_list<T>::operator[](unsigned int index) {
	search_cell(index);
	return ud_temp->value;
}


TEMPL_CONT
void Unidirectional_list<T>::insert(unsigned int index, const T& value) {
}


TEMPL_CONT
void Unidirectional_list<T>::erase(unsigned int index) {
}