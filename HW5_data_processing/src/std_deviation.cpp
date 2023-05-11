#include "std_deviation.hpp"

Std_deviation::Std_deviation() : deviation{0}, difference{0} {}

// В данном классе функция update обрабатывает данные объекта класса Mean (чтобы не производить расчёт среднего значения дважды)
void Std_deviation::update(double next, const IStatistics *other) {
	values.push_back(next);
	difference = 0;
	for (int i = 0; i < values.size(); i++) {

		difference += pow((values[i] - other->value()), 2);
	}

	deviation = sqrt(difference / values.size());
}

double Std_deviation::value() const {
	return deviation;
}

std::string Std_deviation::name() const {
	return "std_dev";
}