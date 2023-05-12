#include <iostream>
#include "Vect.hpp"

int main() {
	Vect<int, 1> my_array{ 10 };
	int i = 1;
	std::cout << i++ << "arr:\n";
	my_array.printArr();
	std::cout << "Size = " << my_array.size() << "\nCapacity = " << my_array.capacity() << std::endl;

	my_array.push_back(3);
	std::cout << i++ << "arr:\n";
	my_array.printArr();
	std::cout << "Size = " << my_array.size() << "\nCapacity = " << my_array.capacity() << std::endl;

	my_array.push_back(2);
	std::cout << i++ << "arr:\n";
	my_array.printArr();
	std::cout << "Size = " << my_array.size() << "\nCapacity = " << my_array.capacity() << std::endl;

	for (int k = 0; k < 10; k++) {
		my_array.push_back(k + 3);
		std::cout << i++ << "arr:\n";
		my_array.printArr();
		std::cout << "Size = " << my_array.size() << "\nCapacity = " << my_array.capacity() << std::endl;
	}

	std::cout << my_array[0] << '\t' << my_array[1] << std::endl;
}
