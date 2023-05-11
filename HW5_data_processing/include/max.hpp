#pragma once

#include "interfaces.hpp"

//Расчёт максимального значения
class Max : public IStatistics {
private: 
	double m_max;
public: 
	Max();

	void update(double next, const IStatistics* other = nullptr) override;
	double value() const override;
	std::string name() const override;
};