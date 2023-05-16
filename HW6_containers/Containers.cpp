#include <iostream>
#include "Vect.hpp"
#include <vector>

//Прототип функции вывода массива на экран (с использованием итератора)
template <typename T>
void print_arr_data(Row<T> &arr);


int main() {

	std::cout << "------------------------------------SEQUENTIAL DYNAMIC ARRAY------------------------------------\n";
	std::cout << "\nCreating an array:\n";
	Row<int> arr{0,1,2,3};
	print_arr_data(arr);

	std::cout << "-------------\n\nGet data about the size and capacity of an array using the SIZE() and CAPACITY() methods:\n";
	std::cout << "size = " << arr.size() << '\n' << "capacity = " << arr.capacity() << '\n';

	std::cout << "-------------\n\nAdding an array using method PUSH_BACK(*value):\n";
	for (int i = 4; i != 10; ++i) {
		arr.push_back(i);
	}
	print_arr_data(arr);

	std::cout << "-------------\n\nShowing the operation of automatic vector size and capacity change uisng private method INCREASE_CAPACITY():\n";
	std::cout << "size = " << arr.size() << '\n' << "capacity = " << arr.capacity() << '\n';


	std::cout << "-------------\n\nRemoving arbitrary values (Cells 3, 5 and 7) from an array using method ERASE(*index*):\n";
	arr.erase(7);
	arr.erase(5);
	arr.erase(3);
	print_arr_data(arr);
	
	std::cout << "-------------\n\nInserting a value at the beginning of an array using method INSERT():\n";
	arr.insert(0, 10);
	print_arr_data(arr);
	
	std::cout << "-------------\n\nInserting a value into the middle of an array using method INSERT():\n";
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


template <typename T>
void print_arr_data(Row<T> &arr)
{
	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		std::cout << *iter << "  ";
	}

	std::cout << "\n";
}