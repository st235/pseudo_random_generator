#include "CycleDetectionTest.h"

#include <fstream>

namespace {

constexpr uint32_t MAX_VALUE = 0xFFFFFFFF;

}

namespace tests {

CycleDetectionTest::CycleDetectionTest(uint32_t sample_size, random_generator::Random *random, uint32_t max_capacity):
    _sample_size(sample_size),
    _max_capacity(max_capacity),
    _random(random) {

}

std::string CycleDetectionTest::title() {
    return "Cycle detection test";
}

Test::Result CycleDetectionTest::run() {
    uint64_t counter = 0;

    uint16_t value = 0;
    while(counter < MAX_VALUE && _cycle_detection.find(value) == _cycle_detection.end()) {
        if (counter > 0) {
            _cycle_detection.insert(value);
        }
        value = _random->next() * _max_capacity;
        counter++;
    }

    if (counter >= MAX_VALUE) {
        _cycle_counter = -1;
        return Result::ERROR;
    }

    _cycle_counter = static_cast<int64_t>(counter);
    return Result::OK;
}

void CycleDetectionTest::saveReport() {
    std::ofstream ofstream;
    ofstream.open("cycle_detection_test_report.txt");
    ofstream << "cycle counter is: " << _cycle_counter << std::endl;
    ofstream.close();
}

}
