#include "NumericCharacteristicsTest.h"

#include <cmath>
#include <iostream>

namespace tests {

NumericCharacteristicsTest::NumericCharacteristicsTest(uint32_t sample_size, random_generator::Random *random):
    _sample_size(sample_size),
    _random(random) {
}

Test* NumericCharacteristicsTest::run() {
    for (uint64_t i = 0; i < _sample_size; i++) {
        _sample.push_back(_random->next());
    }

    _expectedValue = expectedValue();
    _dispersion = dispersion();
    _asymmetryFactor = asymmetryFactor();
    _excessFactor = excessFactor();

    return this;
}

Test* NumericCharacteristicsTest::saveResults() {
    std::cout << "expected value: " << _expectedValue << std::endl
              << "dispersion: " << _dispersion << std::endl
              << "asymmetry factory: " << _asymmetryFactor << std::endl
              << "excess factor: " << _excessFactor << std::endl;

    return this;
}

double NumericCharacteristicsTest::expectedValue() {
    double sum = 0;
    for (double prob: _sample) sum += prob;
    return sum / static_cast<double>(_sample.size());
}

double NumericCharacteristicsTest::dispersion() {
    double expected_value = expectedValue();

    double sum = 0;
    for (double prob: _sample) sum += pow(prob - expected_value, 2);

    return sum / static_cast<double>(_sample.size() - 1);
}

double NumericCharacteristicsTest::asymmetryFactor() {
    double expected_value = expectedValue();
    double dispersion_value = dispersion();

    double sum = 0;
    for (double prob: _sample) sum += pow(prob - expected_value, 3);

    return sum / static_cast<double>(_sample.size() - 1) / pow(dispersion_value, 1.0/3.0);
}

double NumericCharacteristicsTest::excessFactor() {
    double expected_value = expectedValue();
    double dispersion_value = dispersion();

    double sum = 0;
    for (double prob: _sample) sum += pow(prob - expected_value, 4);

    return sum / static_cast<double>(_sample.size() - 1) / pow(dispersion_value, 2) - 3;
}

}
