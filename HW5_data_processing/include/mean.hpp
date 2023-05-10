#pragma once

#include "interfaces.hpp"

// Расчёт среднеарифметического значения
class Mean : public IStatistics {
private:
	double m_sum;
	int m_counter;
	double m_mean;
public:
	Mean();

	void update(double next, const IStatistics *other = nullptr) override;
	double value() const override;
	std::string name() const override;
};