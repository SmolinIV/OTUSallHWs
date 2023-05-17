#include "Interface.hpp"

template <typename T>
class Bidirectional_list {

private:
	struct Cell {
		Cell* lhs;
		T value;
		Cell* rhs;
	} *element;

	Cell* bd_first;
	Cell* bd_last;
public:

	Bidirectional_list();

	Bidirectional_list(std::initializer_list<T> list);
	
	//virtual std::size_t size() const;

	//virtual void push_back(const T& value);

	//virtual T& operator[](unsigned int index) const;

	//virtual void insert(unsigned int index, const T& value);

	//virtual void erase(unsigned int index);

	~Bidirectional_list() {
		delete Cell.lhs;
		delete Cell.rhs;
		Cell.lhs = nullptr;
		Cell.rhs = nullptr;
		delete Cell;
		Cell = nullptr;
	}
};
