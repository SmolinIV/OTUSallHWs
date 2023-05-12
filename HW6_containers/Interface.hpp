#pragma once
#include <iostream>

template <typename T, std::size_t N>
class Interface_Containers {
public:
	virtual ~Interface_Containers() {}

	virtual std::size_t size() const = 0;
	virtual std::size_t capacity() const = 0;

	virtual void push_back(T value) = 0;

};