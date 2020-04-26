#ifndef PSEUDO_RANDOM_GENERATOR_NUMERICCHARACTERISTICSTEST_H
#define PSEUDO_RANDOM_GENERATOR_NUMERICCHARACTERISTICSTEST_H

#include <cstdint>
#include <vector>

#include "../Test.h"
#include "../../src/Random.h"

namespace tests {

class NumericCharacteristicsTest : public Test {
private:
    uint32_t _sample_size;
    std::vector<double> _sample;
    random_generator::Random* _random;

    double _dispersion;
    double _expectedValue;
    double _asymmetryFactor;
    double _excessFactor;

    double dispersion();
    double expectedValue();
    double asymmetryFactor();
    double excessFactor();

public:
    NumericCharacteristicsTest(uint32_t sample_size, random_generator::Random* random);

    Test* run() override;
    Test* saveResults() override;
};

}


#endif //PSEUDO_RANDOM_GENERATOR_NUMERICCHARACTERISTICSTEST_H
