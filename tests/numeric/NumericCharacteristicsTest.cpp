#include "NumericCharacteristicsTest.h"

#include <cmath>
#include <fstream>

namespace {

constexpr double THEORETICAL_EXPECTED_VALUE = 0.5;
constexpr double THEORETICAL_EXPECTED_VALUE_DIFF = 0.1;

constexpr double THEORETICAL_DISPERSION = 1.0 / 12.0;
constexpr double THEORETICAL_DISPERSION_DIFF = 0.01;

constexpr double THEORETICAL_ASYMMETRY_FACTOR = 0;
constexpr double THEORETICAL_ASYMMETRY_FACTOR_DIFF = 0.1;

constexpr double THEORETICAL_EXCESS_FACTOR = - 6.0 / 5.0;
constexpr double THEORETICAL_EXCESS_FACTOR_DIFF = 0.1;

} // anonymous namespace

namespace tests {

NumericCharacteristicsTest::NumericCharacteristicsTest(uint32_t sample_size, random_generator::Random *random):
    _sample_size(sample_size),
    _random(random) {
}

std::string NumericCharacteristicsTest::title() {
    return "Numerical characteristics test";
}

Test::Result NumericCharacteristicsTest::run() {
    for (uint64_t i = 0; i < _sample_size; i++) {
        _sample.push_back(_random->next());
    }

    _expectedValue = expectedValue();

    auto result = Test::Result::OK;

    if (std::abs(_expectedValue - THEORETICAL_EXPECTED_VALUE) > THEORETICAL_EXPECTED_VALUE_DIFF) {
        result = Test::Result::ERROR;
    }

    _dispersion = dispersion();

    if (std::abs(_dispersion - THEORETICAL_DISPERSION) > THEORETICAL_DISPERSION_DIFF) {
        result = Test::Result::ERROR;
    }

    _asymmetryFactor = asymmetryFactor();

    if (std::abs(_asymmetryFactor - THEORETICAL_ASYMMETRY_FACTOR) > THEORETICAL_ASYMMETRY_FACTOR_DIFF) {
        result = Test::Result::ERROR;
    }

    _excessFactor = excessFactor();

    if (std::abs(_excessFactor - THEORETICAL_EXCESS_FACTOR) > THEORETICAL_EXCESS_FACTOR_DIFF) {
        result = Test::Result::ERROR;
    }

    return result;
}

void NumericCharacteristicsTest::saveReport() {
    std::ofstream ofstream;
    ofstream.open("numeric_characterstics_test_report.txt");

    ofstream  << "expected value: " << _expectedValue << std::endl
              << "dispersion: " << _dispersion << std::endl
              << "asymmetry factory: " << _asymmetryFactor << std::endl
              << "excess factor: " << _excessFactor << std::endl;

    ofstream.close();
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
