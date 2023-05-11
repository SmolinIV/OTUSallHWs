#include "percentile.hpp"

Percentile::Percentile(int percent) : p_percent{percent}, p_pct{0} {}

void Percentile::update(double next, const IStatistics *other) {
	values.push_back(next);
	std::sort(values.begin(), values.end());
	int index = values.size() * (p_percent / 100.0);
	p_pct = values[index];
}

double Percentile::value() const {
	return p_pct;
}

std::string Percentile::name() const {
	return "pct" + (std::to_string(p_percent));
}