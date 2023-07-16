// Read files and prints top k word by frequency

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <thread>
#include <sstream>

const size_t TOPK = 4;

using Counter = std::map<std::string, std::size_t>;

std::string tolower(const std::string &str);

void count_words(std::vector<std::string>&, Counter&, int start_line, int end_line);

void print_topk(std::ostream& stream, const std::vector<Counter>&, const size_t k);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: topk_words [FILES...]\n";
        return EXIT_FAILURE;
    }

	auto start = std::chrono::high_resolution_clock::now();
	int num_threads = std::thread::hardware_concurrency();
    Counter c_unused;
    c_unused.emplace("", 0);
	std::vector<Counter> freq_dict;
	freq_dict.reserve(num_threads);
	std::vector<std::string> text;
	for (int i = 1; i < argc; ++i) {
		std::ifstream input{argv[i]};
		if (!input.is_open()) {
			std::cerr << "Failed to open file " << argv[i] << '\n';
			return EXIT_FAILURE;
		}
		std::string str_unused;
		while (std::getline(input, str_unused)) { text.push_back(str_unused); }
        int text_size = text.size();
		int range = text_size / num_threads;
		std::vector<std::thread> threads;
		threads.reserve(num_threads);
		for (int i = 0; i < num_threads; i++) {
            freq_dict.push_back(c_unused);
            std::thread counter_thread{count_words, std::ref(text), std::ref(freq_dict[i]), i*range, (i == num_threads - 1 ? text_size  : ((i + 1) * range) - 1)};
            threads.push_back(std::move(counter_thread));
		}

        for (int i = 0; i < num_threads; i++) {
            threads[i].join();
        }
	}

    print_topk(std::cout, freq_dict, TOPK);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";
}



std::string tolower(const std::string &str) {
    std::string lower_str;
    std::transform(std::cbegin(str), std::cend(str),
                   std::back_inserter(lower_str),
                   [](unsigned char ch) { return std::tolower(ch); });
    return lower_str;
};



void count_words(std::vector<std::string>& text, Counter& counter, int start_line, int end_line){
    for (auto i = text.begin() + start_line; i < text.begin() + end_line; i++) {
        std::istringstream str_stream(*i);
        std::for_each(std::istream_iterator<std::string>(str_stream),
            std::istream_iterator<std::string>(),
            [&counter](const std::string& s) { ++counter[tolower(s)]; });
    }
}



void print_topk(std::ostream& stream, const std::vector<Counter>& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter[0].size());
    for (int i = 0; i < counter.size(); i++) {
        for (auto it = std::cbegin(counter[i]); it != std::cend(counter[i]); ++it) {
            for (int j = 0; j < words.size(); j++) {
                if (words[j]->first == it->first) { words[j]->second += it->second; }

            }
        }
    }
    words.shrink_to_fit();

    std::partial_sort(
        std::begin(words), std::begin(words) + k, std::end(words),
        [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::for_each(
        std::begin(words), std::begin(words) + k,
        [&stream](const Counter::const_iterator &pair) {
            stream << std::setw(4) << pair->second << " " << pair->first
                      << '\n';
        });
}