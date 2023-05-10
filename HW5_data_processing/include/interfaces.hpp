#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>


//Интерфейс
class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next, const IStatistics* other = nullptr) = 0; //Параметр со значением по умолчанию нужен дочернему классу расчёта среднеквадратичного отклонения. см.ниже
	virtual double value() const = 0;
	virtual std::string name() const = 0;
};