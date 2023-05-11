#pragma once

#include "interfaces.hpp"

// ������ ���������� (������������ ��� ����� ����������, ������� �� main ��� ���������� ������� ������)
// ���� � ��� � ���� ��� ������ � ������� ������ mean, ����� �������� ����� (����� ��������� �������� ������������������ �������� ��������, �.�. ����� ���� ����������)
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