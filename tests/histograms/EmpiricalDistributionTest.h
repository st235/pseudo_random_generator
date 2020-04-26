#ifndef PSEUDO_RANDOM_GENERATOR_EMPIRICALDISTRIBUTIONTEST_H
#define PSEUDO_RANDOM_GENERATOR_EMPIRICALDISTRIBUTIONTEST_H

#include <cstdint>
#include <memory>

#include "../Test.h"
#include "../../src/Random.h"
#include "../../tools/analytics/histograms/Histograms.h"
#include "../../tools/export/csv/CsvExporter.h"

namespace tests {

class EmpiricalDistributionTest : public Test {
private:
    uint32_t _sample_size;
    std::unique_ptr<tools::CsvExporter> _exporter;
    std::unique_ptr<tools::Histograms> _histogram;
    random_generator::Random* _random;

public:
    EmpiricalDistributionTest(uint32_t sample_size, random_generator::Random* random);

    Test* run() override;
    Test* saveResults() override;
};

}

#endif //PSEUDO_RANDOM_GENERATOR_EMPIRICALDISTRIBUTIONTEST_H
