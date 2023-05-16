#include "bidirectional_list.hpp"

#define TEMPL_CONT template <typename T>

TEMPL_CONT
Bidirectional_list<T>::Bidirectional_list() {
	element = new Cell;
	element.lhs = nullptr;
	element.rhs = nullptr;
	bd_first = &element;
	bd_last = &element;
}

TEMPL_CONT
Bidirectional_list<T>::Bidirectional_list(std::initializer_list<T> list) : Bidirectional_list(), {
	if(element.lhs)
}