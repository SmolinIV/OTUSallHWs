#include "interfaces.hpp"

// Расчёт минимального значения
class Min : public IStatistics {
private:
	double m_min;
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next, const IStatistics* other = nullptr) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double value() const override {
		return m_min;
	}

	std::string name() const override {
		return "min";
	}

};

//Расчёт максимального значения
class Max : public IStatistics {
private: 
	double m_max;
public: 
	Max() : m_max{std::numeric_limits<double>::min()} {}

	void update(double next, const IStatistics* other = nullptr) override {
		if (next > m_max) {
			m_max = next;
		}
	}

	double value() const override {
		return m_max;
	}

	std::string name() const override {
		return "max";
	}

};

// Расчёт среднеарифметического значения
class Mean : public IStatistics {
private:
	double m_sum;
	int m_counter;
	double m_mean;
public:
	Mean() : m_sum{ 0 }, m_counter{ 0 }, m_mean{ 0 } {}

	void update(double next, const IStatistics *other = nullptr) override {
		m_sum += next;
		++m_counter;
		m_mean = m_sum / m_counter;
	}

	double value() const override {
		return m_mean;
	}

	std::string name() const override {
		return "mean";
	}
};

// Расчёт значения среднеквадратичного отклонения
class Std_deviation : public IStatistics {
private:
	std::vector<double> values;
	double deviation;
	double difference;
public:
	Std_deviation() : deviation{ 0 }, difference{ 0 } {}

	//В данном классе функция update обрабатывает данные объекта класса Mean, чтобы не производить расчёт среднего значения дважды)
	void update(double next, const IStatistics* other) override {
		values.push_back(next);
		difference = 0;
		for (int i = 0; i < values.size(); i++) {

			difference += pow((values[i] - other->value()), 2);
		}

		deviation = sqrt(difference / values.size());
	}

	double value() const override {
		return deviation;
	}

	std::string name() const override {
		return "std_dev";
	}

	const std::vector<double> *get_vector() const {
		return &values;
	}
};

// Расчёт процентиля (унифицирован под любой процентиль, задаётся из main при объявлении объекта класса)
// Хоть у нас и есть уже вектор в объекте класса mean, здесь создаётся новый (чтобы сохранить исходную последовательность введённых значений, т.к. здесь есть сортировка)
class Percentile : public IStatistics {
private:
	std::vector<double> values;
	int p_percent;
	double p_pct;

public:
	Percentile(int percent) : p_percent{ percent }, p_pct{ 0 } {}

	void update(double next, const IStatistics* other) override {
		values.push_back(next);
		std::sort(values.begin(), values.end());
		int index = values.size() * (p_percent / 100.0);
		p_pct = values[index];
	}

	double value() const override {
		return p_pct;
	}

	std::string name() const override {

		return "pct" + (std::to_string(p_percent));
	}

};

