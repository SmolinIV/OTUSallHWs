#include <iostream>
#include "Vect.hpp"

template <typename T>
void print_arr_data(const Row<T> &arr);


int main() {
	Row<int> arr{ 1,2,3 };

	print_arr_data(arr);

	arr.erase(1);
	print_arr_data(arr);

	auto iter = arr.begin();
	std::cout << iter << std::endl;
}


template <typename T>
void print_arr_data(const Row<T> &arr)
{
	std::cout 
		<< "size = " << arr.size() << '\n' 
		<< "capacity = " << arr.capacity() << '\n';
	arr.print();
}