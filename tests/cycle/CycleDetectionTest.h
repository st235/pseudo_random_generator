#ifndef PSEUDO_RANDOM_GENERATOR_CYCLEDETECTIONTEST_H
#define PSEUDO_RANDOM_GENERATOR_CYCLEDETECTIONTEST_H

#include <cstdint>
#include <unordered_set>

#include "../Test.h"
#include "../../src/Random.h"

namespace tests {


class CycleDetectionTest: public Test {
private:
    int64_t _cycle_counter;
    int32_t _max_capacity;
    uint32_t _sample_size;
    std::unordered_set<uint32_t> _cycle_detection;
    random_generator::Random* _random;

public:
    CycleDetectionTest(uint32_t sample_size, uint32_t max_capacity, random_generator::Random* random);

    Test* run() override;
    Test* saveResults() override;
};

}

#endif //PSEUDO_RANDOM_GENERATOR_CYCLEDETECTIONTEST_H
