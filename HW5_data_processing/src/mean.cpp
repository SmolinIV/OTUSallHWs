#include "mean.hpp"

Mean::Mean() : m_sum{ 0 }, m_counter{ 0 }, m_mean{ 0 } {}

void Mean::update(double next, const IStatistics *other) {
	m_sum += next;
	++m_counter;
	m_mean = m_sum / m_counter;
}

double Mean::value() const {
	return m_mean;
}

std::string Mean::name() const {
	return "mean";
}