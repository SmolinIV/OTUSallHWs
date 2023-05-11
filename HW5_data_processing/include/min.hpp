#pragma once

#include "interfaces.hpp"

//������ ������������ ��������
class Min : public IStatistics {
private:
	double m_min;
public:
	Min();

	void update(double next, const IStatistics* other = nullptr) override;
	double value() const override;
	std::string name() const override;
};