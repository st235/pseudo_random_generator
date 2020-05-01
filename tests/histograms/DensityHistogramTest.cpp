#include "DensityHistogramTest.h"

namespace tests {

DensityHistogramTest::DensityHistogramTest(uint32_t sample_size, random_generator::Random *random):
        _sample_size(sample_size),
        _random(random) {
    _exporter = std::make_unique<tools::CsvExporter>("density_histogram_test", 2);
    _histogram = std::make_unique<tools::Histograms>(10);
}

std::string DensityHistogramTest::title() {
    return "Density histogram test";
}

Test::Result DensityHistogramTest::run() {
    for (uint64_t i = 0; i < _sample_size; i++) {
        _histogram->countPointAt(_random->next());
    }

    return Test::Result::OK;
}

void DensityHistogramTest::saveReport() {
    const auto& rawHistogram = _histogram->rawHistogram();

    for (auto i: rawHistogram) {
        auto value = (static_cast<double>(i.second) / static_cast<double>(_histogram->getCount())) / _histogram->getIntervalLength();
        std::string values[] = { std::to_string(i.first), std::to_string(value) };
        _exporter->addRow(values);
    }
}

}
