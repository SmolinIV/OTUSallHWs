#include <iostream>
#include "Row.hpp"
#include "bidirectional_list.hpp"
#include "unidirectional_list.hpp"

//Прототип функций:
// Вывод массива типа Row на экран (с использованием итератора)
template <typename T>
void print_arr_data(Row<T> &arr);

// Функции разделяют работу трё разных контейнеров. Разделил просто для удобства работы и проверки, чтобы убрать сплошной код в main :)
void working_with_dinamic_array();
void working_with_bidirect_list();
void working_with_unidirect_list();

int main() {

	std::cout << "------------------------------------SEQUENTIAL DYNAMIC ARRAY------------------------------------\n";
	working_with_dinamic_array();

	std::cout << "\n---------------------------------------BIDIRECTIONAL LIST---------------------------------------\n";
	working_with_bidirect_list();

	std::cout << "\n--------------------------------------UNIDIRECTIONAL LIST--------------------------------------\n";
	working_with_unidirect_list();

}

//Демонстрация работы с динамическим последовательным массивом (Row)
void working_with_dinamic_array() {
	std::cout << "\nCreating an array:\n";
	Row<int> arr{ 0,1,2,3 };
	print_arr_data(arr);

	std::cout << "-------------\n\nGet data about the size and capacity of the array using the SIZE() and CAPACITY() methods:\n";
	std::cout << "size = " << arr.size() << '\n' << "capacity = " << arr.capacity() << '\n';

	std::cout << "-------------\n\nAdding the array using method PUSH_BACK(*value):\n";
	for (int i = 4; i != 10; ++i) {
		arr.push_back(i);
	}
	print_arr_data(arr);

	std::cout << "-------------\n\nShowing the operation of automatic array size and capacity change uisng private method INCREASE_CAPACITY():\n";
	std::cout << "size = " << arr.size() << '\n' << "capacity = " << arr.capacity() << '\n';


	std::cout << "-------------\n\nRemoving arbitrary values (Cells 3, 5 and 7) from the array using method ERASE(*index*):\n";
	arr.erase(7);
	arr.erase(5);
	arr.erase(3);
	print_arr_data(arr);

	std::cout << "-------------\n\nInserting a value at the beginning of the array using method INSERT(*index*, *value*):\n";
	arr.insert(0, 10);
	print_arr_data(arr);

	std::cout << "-------------\n\nInserting a value into the middle of the array using method INSERT(*index*, *value*):\n";
	arr.insert(arr.size() / 2, 20);
	print_arr_data(arr);

	std::cout << "-------------\n\nReducing the array capacity to the actual size using method SHRINK_TO_FIT():\n";
	std::cout << "Before reducing:\n";
	std::cout << "size = " << arr.size() << '\n' << "capacity = " << arr.capacity() << "\n\n";

	arr.shrink_to_fit();

	std::cout << "After reducing:\n";
	std::cout << "size = " << arr.size() << '\n' << "capacity = " << arr.capacity() << '\n';

	std::cout << std::endl;

}

// Демонстрация работы с двунаправленным списком (Bidirectional_list)
void working_with_bidirect_list() {
	std::cout << "\nCreating a list:\n";
	Bidirectional_list<int> list{ 1,2,3 };
	list.print_list();

	std::cout << "-------------\n\nGet data about the size of the list using the method SIZE():\n";
	std::cout << "size = " << list.size() << '\n';

	std::cout << "-------------\n\nAdding the list using method PUSH_BACK(*value):\n";
	for (int i = 4; i != 10; ++i) {
		list.push_back(i);
	}
	list.print_list();

	std::cout << "-------------\n\nRemoving arbitrary values (Cells 3, 5 and 7) from the list using method ERASE(*index*):\n";
	list.erase(7);
	list.erase(5);
	list.erase(3);
	list.print_list();

	std::cout << "-------------\n\nInserting a value at the beginning of the list using method INSERT(*index*, *value*):\n";
	list.insert(0, 10);
	list.print_list();

	std::cout << "-------------\n\nInserting a value into the middle of the list using method INSERT(*index*, *value*):\n";
	list.insert(list.size() / 2, 20);
	list.print_list();

	std::cout << std::endl;
}

// Демонстрация работы с однонаправленным списком (Unidirectional_list)
void working_with_unidirect_list() {
	std::cout << "\nCreating a list:\n";
	Unidirectional_list<int> u_list{ 1,2,3 };
	u_list.print_list();

	std::cout << "-------------\n\nGet data about the size of the list using the method SIZE():\n";
	std::cout << "size = " << u_list.size() << '\n';

	std::cout << "-------------\n\nAdding the list using method PUSH_BACK(*value):\n";
	for (int i = 4; i != 10; ++i) {
		u_list.push_back(i);
	}
	u_list.print_list();

	std::cout << "-------------\n\nRemoving arbitrary values (Cells 3, 5 and 7) from the list using method ERASE(*index*):\n";
	u_list.erase(7);
	u_list.erase(5);
	u_list.erase(3);
	u_list.print_list();

	std::cout << "-------------\n\nInserting a value at the beginning of the list using method INSERT(*index*, *value*):\n";
	u_list.insert(0, 10);
	u_list.print_list();

	std::cout << "-------------\n\nInserting a value into the middle of the list using method INSERT(*index*, *value*):\n";
	u_list.insert(u_list.size() / 2, 20);
	u_list.print_list();

	std::cout << std::endl;
}

// Вывод Row-массива на экран. (Для демонстрации работы итератора)
template <typename T>
void print_arr_data(Row<T> &arr)
{
	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		std::cout << *iter << "  ";
	}

	std::cout << "\n";
}