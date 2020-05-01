#ifndef PSEUDO_RANDOM_GENERATOR_DISTRIBUTIONTEST_H
#define PSEUDO_RANDOM_GENERATOR_DISTRIBUTIONTEST_H

#include <cstdint>
#include <vector>

#include "../Test.h"
#include "../../src/Random.h"

namespace tests {

class DistributionTest: public Test {
private:
    uint32_t _sample_size;
    random_generator::Random* _random;

    double _positive_deviation;
    double _negative_deviation;

    double _statistics_deviation;

public:
    DistributionTest(uint32_t sample_size, random_generator::Random* random);

    Test* run() override;
    Test* saveResults() override;
};

}

#endif //PSEUDO_RANDOM_GENERATOR_DISTRIBUTIONTEST_H
