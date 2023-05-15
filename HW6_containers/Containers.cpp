#include <iostream>
#include "Vect.hpp"
#include <vector>


int main() {
	Row<int> arr{ 1,2,3,4,5,6,8,9,10};

	arr.print();

	arr.insert(2, 12);

	arr.print();

	std::vector<int> v{ 0,4,5};

	std::cout << v.size();

	v.erase(v.begin());

	std::cout << v.size();

}
