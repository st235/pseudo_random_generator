#include "DistributionTest.h"

#include "cmath"
#include <fstream>

namespace {

constexpr double THEORETICAL_SIGNIFICANCE_LEVEL[] = {0.15, 0.1, 0.05, 0.025, 0.01 };
constexpr double THEORETICAL_DEVIATION[] = { 1.138, 1.224, 1.358, 1.480, 1.628 };

} // anonymous namespace

namespace tests {

DistributionTest::DistributionTest(uint32_t sample_size, random_generator::Random *random):
    _sample_size(sample_size),
    _random(random),
    _positive_deviation(std::numeric_limits<double>::min()),
    _negative_deviation(std::numeric_limits<double>::min()) {
}

std::string DistributionTest::title() {
    return "Distribution test";
}

Test::Result DistributionTest::run() {
    std::vector<double> values;
    for (uint64_t i = 0; i < _sample_size; i++) {
        values.push_back(_random->next());
    }

    std::sort(values.begin(), values.end());

    auto n = static_cast<double>(_sample_size);
    auto sqrt_n = std::sqrt(static_cast<double>(_sample_size));

    for (uint64_t i = 0; i < _sample_size; i++) {
        _positive_deviation = std::max(
                _positive_deviation,
                static_cast<double>(i + 1) / (n + 1) - values[i]
        );

        _negative_deviation = std::max(
                _negative_deviation,
                values[i] - static_cast<double>(i + 1) / (n + 1)
        );
    }

    auto max_deviation = std::max(_positive_deviation, _negative_deviation);
    _statistics_deviation = (max_deviation + 0.4 / n) * (sqrt_n + 0.2 + 0.68 / sqrt_n);

    int table_size = sizeof(THEORETICAL_DEVIATION) / sizeof(double);

    for (int i = 0; i < table_size; i++) {
        if (_statistics_deviation <= THEORETICAL_DEVIATION[i]) {
            return Test::Result::OK;
        }
    }

    return Test::Result::ERROR;
}

void DistributionTest::saveReport() {
    std::ofstream ofstream;
    ofstream.open("distribution_test_report.txt");

    int table_size = sizeof(THEORETICAL_DEVIATION) / sizeof(double);

    for (int i = 0; i < table_size; i++) {
        if (_statistics_deviation <= THEORETICAL_DEVIATION[i]) {
            ofstream << "statistics deviation is: " << _statistics_deviation << std::endl
                      << "matched theoretical threshold: " << THEORETICAL_DEVIATION[i] << std::endl
                      << "significance level is: " << THEORETICAL_SIGNIFICANCE_LEVEL[i] << std::endl;
            return;
        }
    }

    ofstream << "threshold not found, base hypothesis declined, deviation is: " << _statistics_deviation << std::endl;
    ofstream.close();
}

}
