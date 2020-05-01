#ifndef PSEUDO_RANDOM_GENERATOR_TESTRUNNER_H
#define PSEUDO_RANDOM_GENERATOR_TESTRUNNER_H

#include <cstdint>
#include <vector>
#include <memory>

#include "Test.h"
#include "../src/Random.h"
#include "RecordedRandom.h"

namespace tests {

class TestRunner {
private:
    uint32_t _sample_size;
    std::unique_ptr<RecordedRandom> _random;
    std::vector<std::unique_ptr<Test>> _tests;

public:
    TestRunner(uint32_t sample_size, random_generator::Random* random);

    template<class T, class... Args>
    TestRunner* addTest(Args&&... args) {
        _tests.emplace_back(std::make_unique<T>(_sample_size, _random.get(), args...));
        return this;
    }

    void run();
};

}

#endif //PSEUDO_RANDOM_GENERATOR_TESTRUNNER_H
