#pragma once

#include "interfaces.hpp"

// Расчёт процентиля (унифицирован под любой процентиль, задаётся из main при объявлении объекта класса)
// Хоть у нас и есть уже вектор в объекте класса mean, здесь создаётся новый (чтобы сохранить исходную последовательность введённых значений, т.к. здесь есть сортировка)
class Percentile : public IStatistics {
private:
	std::vector<double> values;
	int p_percent;
	double p_pct;

public:
	Percentile(int percent);

	void update(double next, const IStatistics* other) override;
	double value() const override;
	std::string name() const override;

};