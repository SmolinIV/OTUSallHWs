#include <iostream>
#include "Vect.hpp"
#include "bidirectional_list.hpp"
#include "unidirectional_list.hpp"

//Прототип функции вывода массива на экран (с использованием итератора)
template <typename T>
void print_arr_data(Row<T> &arr);


int main() {

	std::cout << "------------------------------------SEQUENTIAL DYNAMIC ARRAY------------------------------------\n";
	std::cout << "\nCreating an array:\n";
	Row<int> arr{ 0,1,2,3 };
	print_arr_data(arr);

	std::cout << "-------------\n\nGet data about the size and capacity of an array using the SIZE() and CAPACITY() methods:\n";
	std::cout << "size = " << arr.size() << '\n' << "capacity = " << arr.capacity() << '\n';
	/*
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
	*/

	Bidirectional_list<int> list{1,2,3};
	
	list.push_back(4);
	list.push_back(5);
	for (int i = 0; i < list.size(); i++)
	{
	std::cout << list[i] << "  ";
	}

	list.insert(1, 10);
	list.insert(4, 11);
	list.insert(6, 12);

	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list[i] << "  ";
	}
	std::cout << "\n\n";
	list.erase(list.size() - 1);
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list[i] << "  ";
	}
	std::cout << "\n\n";
	list.erase(0);
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list[i] << "  ";
	}
	list.erase(1);
	std::cout << "\n\n";

	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list[i] << "  ";
	}
	std::cout << "\n\n";
	std::cout << list.size() << std::endl;

	std::cout << "------UNIDIRECTIONAL LIST!!!--------\n\n";

	Unidirectional_list<int> list2{ 1,2,3 };

	list2.push_back(4);
	list2.push_back(5);
	list2.push_back(6);
	for (int i = 0; i < list2.size(); i++)
	{
		std::cout << list2[i] << "  ";
	}

	
	std::cout << "\n" << list2.size()  << "\n\n";
	


	
}

template <typename T>
void print_arr_data(Row<T> &arr)
{
	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		std::cout << *iter << "  ";
	}

	std::cout << "\n";
}