// Определение методов класса Vect
#define TEMPL_CONT template <typename T>


// Конструктор "по умолчанию"
TEMPL_CONT
Row<T>::Row() {
	v_size = N;
	v_capacity = N * v_koef;
	v_arr = new T[v_capacity];
	v_last = 0;
}

// Конструктор с параметрами (с делигированием к конструктору по умолчанию)
TEMPL_CONT
Row<T>::Row(std::initializer_list<T> list) : Row() {
	for (auto i : list)
	{
		push_back(i);
	}
	//for (int i = v_last; i < v_size; i++)
	//{
	//	v_arr[i] = (T)0;
	//}
}

// Изменние ёмкости вектора
TEMPL_CONT
void Row<T>::increase_capacity() {
	v_capacity = v_size * v_koef;
	T* temp_arr = new T[v_capacity];

	for (int i = 0; i < v_size; i++) {
		temp_arr[i] = v_arr[i];
	}

	delete[] v_arr;
	v_arr = temp_arr;
	temp_arr = nullptr;
}

// Добавление элемента в конец последовательности уже находящихся в контейнере элементов (не в конец контейнера!)
TEMPL_CONT 
void Row<T>::push_back(const T& value) {
	if (v_last < v_capacity) {
		v_arr[v_last] = value;

		if (v_last == v_size) {
			++v_size;
		}
		++v_last;
	}
	else {
		this->increase_capacity();
		this->push_back(value);
	}
}

TEMPL_CONT
void Row<T, N>::insert(unsigned int index, const T& value)
{
	push_back(value);
	for (int i = v_last - 1; i > index; i--) {
		std::swap(v_arr[i], v_arr[i - 1]);
	}
}

TEMPL_CONT
void Row<T,N>::erase(unsigned int index) {
	for (int i = index; i < v_last; i++) {

	}
}