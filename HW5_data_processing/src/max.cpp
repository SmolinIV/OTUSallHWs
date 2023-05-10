#include "max.hpp"

Max::Max() : m_max{std::numeric_limits<double>::lowest()} {}

void Max::update(double next, const IStatistics *other) {
	if (next > m_max) {
		m_max = next;
	}
}

double Max::value() const {
	return m_max;
}

std::string Max::name() const {
	return "max";
}