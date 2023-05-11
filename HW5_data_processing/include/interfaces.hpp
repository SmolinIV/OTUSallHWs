#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>


//���������
class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next, const IStatistics* other = nullptr) = 0; //�������� �� ��������� �� ��������� ����� ��������� ������ ������� ������������������� ����������. ��.����
	virtual double value() const = 0;
	virtual std::string name() const = 0;
};