#pragma once

#include "interfaces.hpp"

// ������ �������� ������������������� ����������
class Std_deviation : public IStatistics {
private:
	std::vector<double> values;
	double deviation;
	double difference;
public:
	Std_deviation();

	//� ������ ������ ������� update ������������ ������ ������� ������ Mean, ����� �� ����������� ������ �������� �������� ������)
	void update(double next, const IStatistics* other) override;
	double value() const override;
	std::string name() const override;
};