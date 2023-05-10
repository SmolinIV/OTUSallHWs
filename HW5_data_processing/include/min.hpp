#pragma once

#include "interfaces.hpp"

//Расчёт минимального значения
class Min : public IStatistics {
private:
	double m_min;
public:
	Min();

	void update(double next, const IStatistics* other = nullptr) override;
	double value() const override;
	std::string name() const override;
};