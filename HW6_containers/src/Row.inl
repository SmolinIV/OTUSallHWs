// Определение методов класса Vect
#define TEMPL_CONT template <typename T>

// Конструктор "по умолчанию"
TEMPL_CONT
Row<T>::Row() {
	r_size = 0;
	r_capacity = 5;
	r_arr = new T[r_capacity];
	r_last = 0;
}

// Конструктор переноса
TEMPL_CONT
Row<T>::Row(Row&& other) {
	r_size = other.r_size;
	r_capacity = other.r_capacity;
	r_last = other.r_last;
	r_arr = other.r_arr;
	other.~Row();
	//other.r_size = nullptr;
	//other.r_last = nullptr;
	//other.r_capacity = nullptr;
	//other.r_arr = nullptr;
}

//Конструктор копирования
TEMPL_CONT
Row<T>::Row(const Row& other) {
	r_size = other.r_size;
	r_capacity = other.r_capacity;
	r_last = other.r_last;
	r_arr = new T[r_capacity];
	for (int i = 0; i < r_last; i++)
	{
		r_arr[i] = other.r_arr[i];
	}
}

// Конструктор с параметрами
TEMPL_CONT
Row<T>::Row(std::initializer_list<T> list) {
	r_size = list.size();
	r_capacity = r_size * r_koef;
	r_arr = new T[r_capacity];
	r_last = 0;
	for (auto i : list)
	{
		push_back(i);
	}
}

// Изменние ёмкости вектора
TEMPL_CONT
void Row<T>::increase_capacity() {
	r_capacity = r_size * r_koef;
	T* temp_arr = new T[r_capacity];

	for (int i = 0; i < r_size; i++) {
		temp_arr[i] = r_arr[i];
	}

	delete[] r_arr;
	r_arr = temp_arr;
	temp_arr = nullptr;
}


// Добавление элемента в конец последовательности уже находящихся в контейнере элементов (не в конец контейнера!)
TEMPL_CONT 
void Row<T>::push_back(const T& value) {
	if (r_last < r_capacity) {
		r_arr[r_last] = value;

		if (r_last == r_size) {
			++r_size;
		}
		++r_last;
	}
	else {
		this->increase_capacity();
		this->push_back(value);
	}
}

//Вставка элемента в указанную ячейку
TEMPL_CONT
void Row<T>::insert(unsigned int index, const T& value)
{
	push_back(value);
	for (int i = r_last - 1; i > index; i--) {
		std::swap(r_arr[i], r_arr[i - 1]);
	}
}

// Удаление элемента из заданной ячейки
TEMPL_CONT
void Row<T>::erase(unsigned int index) {
	for (int i = index - 1; i < r_last; i++) {
		std::swap(r_arr[i], r_arr[i + 1]);
	}
	r_last = --r_size;
}

// Уменьшение выделенной "запосной" памяти до уровня реального размера массива
TEMPL_CONT
void Row<T>::shrink_to_fit() {
	T* temp_arr = new T[r_size];
	for (int i = 0; i < r_size; i++)
	{
		temp_arr[i] = r_arr[i];
	}
	delete[] r_arr;
	r_arr = temp_arr;
	temp_arr = nullptr;
	r_capacity = r_size;
}

//Итератор с указанием на начало массива
TEMPL_CONT
Iterator<T> Row<T>::begin() {
	r_iter = &r_arr[0];
	return r_iter;
}

//Итератор с указанием на конец массива
TEMPL_CONT
Iterator<T> Row<T>::end() {
	r_iter = &r_arr[r_last];
	return r_iter;
}