#pragma once

#include "interfaces.hpp"

// Расчёт значения среднеквадратичного отклонения
class Std_deviation : public IStatistics {
private:
	std::vector<double> values;
	double deviation;
	double difference;
public:
	Std_deviation();

	//В данном классе функция update обрабатывает данные объекта класса Mean, чтобы не производить расчёт среднего значения дважды)
	void update(double next, const IStatistics* other) override;
	double value() const override;
	std::string name() const override;
};