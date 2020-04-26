#include "CycleDetectionTest.h"

#include <iostream>

namespace {

constexpr uint32_t MAX_VALUE = 0xFFFFFFFF;

}

namespace tests {

CycleDetectionTest::CycleDetectionTest(uint32_t sample_size, uint32_t max_capacity, random_generator::Random *random):
    _sample_size(sample_size),
    _max_capacity(max_capacity),
    _random(random) {

}

Test* CycleDetectionTest::run() {
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
    } else {
        _cycle_counter = static_cast<int64_t>(counter);
    }

    return this;
}

Test* CycleDetectionTest::saveResults() {
    std::cout << "cycle counter is: " << _cycle_counter << std::endl;
    return this;
}

}
