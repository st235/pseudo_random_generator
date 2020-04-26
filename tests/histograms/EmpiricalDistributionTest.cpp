#include "EmpiricalDistributionTest.h"

namespace tests {

    EmpiricalDistributionTest::EmpiricalDistributionTest(uint32_t sample_size, random_generator::Random *random):
        _sample_size(sample_size),
        _random(random) {
    _exporter = std::make_unique<tools::CsvExporter>("empirical_distribution_test", 2);
    _histogram = std::make_unique<tools::Histograms>(10);
}

Test* EmpiricalDistributionTest::run() {
    for (uint64_t i = 0; i < _sample_size; i++) {
        _histogram->countPointAt(_random->next());
    }

    return this;
}

Test* EmpiricalDistributionTest::saveResults() {
    const auto& rawHistogram = _histogram->rawHistogram();

    uint64_t currentSum = 0;

    for (auto i: rawHistogram) {
        currentSum += i.second;
        auto value = (static_cast<double>(currentSum) / static_cast<double>(_histogram->getCount()));
        std::string values[] = { std::to_string(i.first), std::to_string(value) };
        _exporter->addRow(values);
    }

    return this;
}

}
