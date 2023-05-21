// Определение методов класса unidirectional_list
#define TEMPL_CONT template <typename T>

// Конструктор по умолчанию
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

// Добавление нового элемента в конец списка
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

// Вставка элеманта по указанному индексу
TEMPL_CONT
void Unidirectional_list<T>::insert(unsigned int index, const T& value) {
	Cell* new_cell = new Cell;
	new_cell->value = value;

	if (index == 0) {
		new_cell->rhs = ud_first;
		ud_first = new_cell;

	}
	else {
		search_cell(index - 1); // -1, т.к. список однонаправленный 
		new_cell->rhs = ud_temp->rhs;
		ud_temp->rhs = new_cell;
	}
	new_cell = nullptr;
	++ud_size;
}

// Удаление элемента по указанному индексу
TEMPL_CONT
void Unidirectional_list<T>::erase(unsigned int index) {
	Cell* erasing_cell;
	if (index == 0) {
		erasing_cell = ud_first;
		ud_first = ud_first->rhs;
	}
	else {
		search_cell(index - 1);  // -1, т.к. список однонаправленный 
		erasing_cell = ud_temp->rhs;
		ud_temp->rhs = erasing_cell->rhs;
	}
	erasing_cell->rhs = nullptr;
	delete erasing_cell;
	erasing_cell = nullptr;

	--ud_size;
}

// Удобный вывод массива на экран
TEMPL_CONT
void Unidirectional_list<T>::print_list() {
	ud_temp = ud_first;
	while (ud_temp) {
		std::cout << ud_temp->value << "  ";
		ud_temp = ud_temp->rhs;
	}
	std::cout << "\n\n";
}