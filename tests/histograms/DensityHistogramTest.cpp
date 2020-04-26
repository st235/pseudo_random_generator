#include "DensityHistogramTest.h"

namespace tests {

DensityHistogramTest::DensityHistogramTest(uint32_t sample_size, random_generator::Random *random):
        _sample_size(sample_size),
        _random(random) {
    _exporter = std::make_unique<tools::CsvExporter>("density_histogram_test", 2);
    _histogram = std::make_unique<tools::Histograms>(10);
}

Test* DensityHistogramTest::run() {
    for (uint64_t i = 0; i < _sample_size; i++) {
        _histogram->countPointAt(_random->next());
    }

    return this;
}

Test* DensityHistogramTest::saveResults() {
    const auto& rawHistogram = _histogram->rawHistogram();

    for (auto i: rawHistogram) {
        std::string values[] = { std::to_string(i.first), std::to_string(static_cast<long>(i.second)) };
        _exporter->addRow(values);
    }

    return this;
}

}
