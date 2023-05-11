#include "min.hpp"

Min::Min() : m_min{std::numeric_limits<double>::max()} {}

void Min::update(double next, const IStatistics *other) {
	if (next < m_min) {
		m_min = next;
	}
}

double Min::value() const {
	return m_min;
}

std::string Min::name() const {
	return "min";
}