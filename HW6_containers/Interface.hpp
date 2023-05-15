#pragma once
#include <iostream>


template <typename T>
class Interface_Containers {
public:
	virtual ~Interface_Containers() {}

	virtual std::size_t size() const = 0;

	virtual void push_back(const T& value) = 0;

	virtual T& operator[](unsigned int index) const = 0;

	virtual void insert(unsigned int index, const T& value) = 0;

	virtual void erase(unsigned int index) = 0;
};