#ifndef PSEUDO_RANDOM_GENERATOR_PLANEDISTRIBUTIONTEST_H
#define PSEUDO_RANDOM_GENERATOR_PLANEDISTRIBUTIONTEST_H

#include "../Test.h"

#include <cstdint>
#include <memory>
#include "../../src/Random.h"
#include "../../tools/analytics/drawing/Chart.h"

namespace tests {

class PlaneDistributionTest: public Test {
private:
    uint16_t _dimension;
    uint32_t _sample_size;
    random_generator::Random* _random;
    std::unique_ptr<tools::Chart> _chart;

    uint32_t _previous;
    uint32_t _current;

    uint16_t nextInt();

public:
    PlaneDistributionTest(uint16_t dimension, uint32_t sample_size, random_generator::Random* random);

    Test* run() override;
    Test* saveResults() override;
};

}

#endif //PSEUDO_RANDOM_GENERATOR_PLANEDISTRIBUTIONTEST_H
