#include "interfaces.hpp"
#include "statistics.cpp"


int main() {

	enum Stats {
		MIN,
		MAX,
		MEAN,
		DEVIATION,
		PERCENTILE90,
		PERCENTILE95,
		ALL_STATS
	};

	const size_t statistics_count = Stats::ALL_STATS;
	IStatistics *statistics[statistics_count];

	statistics[Stats::MIN] = new Min{};
	statistics[Stats::MAX] = new Max{};
	statistics[Stats::MEAN] = new Mean{};
	statistics[Stats::DEVIATION] = new Std_deviation{};
	statistics[Stats::PERCENTILE90] = new Percentile{90};
	statistics[Stats::PERCENTILE95] = new Percentile{95};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			switch (i) {
			case Stats::MIN:
			case Stats::MAX:
			case Stats::MEAN:
			case Stats::PERCENTILE90:
			case Stats::PERCENTILE95:
				statistics[i]->update(val);
				break;
			case Stats::DEVIATION:
				statistics[i]->update(val, statistics[i - 1]);
				break;
				default:
				break;
			}
		}
	}



	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->value() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}