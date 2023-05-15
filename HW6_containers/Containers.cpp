#include <iostream>
#include "Vect.hpp"
#include <vector>

template <typename T>
void print_arr_data(const Row<T> &arr);


int main() {
	Row<int> arr{0,1,2,3};
	//print_arr_data(arr);
	std::cout << "size = " << arr.size() << '\n' << "capacity = " << arr.capacity() << '\n';
	std::cout << "|";
	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		std::cout << "  " << *iter << "  |";
	}
	std::cout << "\n\n";

	for (int i = 4; i != 10; ++i) {
		arr.push_back(i);
	}
	//print_arr_data(arr);
	std::cout << "size = " << arr.size() << '\n' << "capacity = " << arr.capacity() << '\n';
	std::cout << "|";
	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		std::cout << "  " << *iter << "  |";
	}
	std::cout << "\n\n";

	arr.erase(7);
	arr.erase(5);
	arr.erase(3);
	//print_arr_data(arr);
	std::cout << "|";
	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		std::cout << "  " << *iter << "  |";
	}
	std::cout << "\n\n";

	arr.insert(0, 10);
	//print_arr_data(arr);
	std::cout << "|";
	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		std::cout << "  " << *iter << "  |";
	}
	std::cout << "\n\n";

	arr.insert(arr.size() / 2, 20);
	//print_arr_data(arr);
	std::cout << "|";
	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		std::cout << "  " << *iter << "  |";
	}
	std::cout << "\n\n";

	std::cout << std::endl;
}


//template <typename T>
//void print_arr_data(const Row<T> &arr)
//{
//	std::cout 
//		<< "size = " << arr.size() << '\n' 
//		<< "capacity = " << arr.capacity() << '\n';
//
//	std::cout << "|";
//	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
//		std::cout << "  " << *iter << "  |";
//	}
//
//	std::cout << "\n\n";
//}