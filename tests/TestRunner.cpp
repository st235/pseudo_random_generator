#include "TestRunner.h"

#include <iostream>

namespace {

constexpr char RESET[] = "\033[0m";
constexpr char BLACK[] = "\033[30m";
constexpr char RED[] = "\033[31m";
constexpr char GREEN[] = "\033[32m";
constexpr char YELLOW[] = "\033[33m";
constexpr char BLUE[]  = "\033[34m";
constexpr char MAGENTA[] = "\033[35m";
constexpr char CYAN[]  = "\033[36m";
constexpr char WHITE[] = "\033[37m";
constexpr char BOLDBLACK[] = "\033[1m\033[30m";
constexpr char BOLDRED[] = "\033[1m\033[31m";
constexpr char BOLDGREEN[] = "\033[1m\033[32m";
constexpr char BOLDYELLOW[] = "\033[1m\033[33m";
constexpr char BOLDBLUE[] = "\033[1m\033[34m";
constexpr char BOLDMAGENTA[] = "\033[1m\033[35m";
constexpr char BOLDCYAN[] = "\033[1m\033[36m";
constexpr char BOLDWHITE[] = "\033[1m\033[37m";
    
} // anonymous namespace

namespace tests {

TestRunner::TestRunner(uint32_t sample_size, random_generator::Random* random): _sample_size(sample_size) {
    _random = RecordedRandom::wrap(sample_size, random);
}

void TestRunner::run() {
    _random->flush();

    uint32_t counter = 1;
    uint32_t passed = 0;

    std::cout << "Test set size is " << _tests.size() << " tests. Running..." << std::endl;

    for (auto& test: _tests) {
        const auto& result = test->run();

        std::cout << "[" << counter << "/" << _tests.size() << "] "
                  << test->title() << " finished with status: ";

        if (result == Test::Result::OK) {
            std::cout << GREEN << "PASSED" << RESET << std::endl;
            passed++;
        } else {
            std::cout << RED << "FAILED" << RESET << std::endl;
        }

        test->saveReport();
        counter++;
    }

    std::cout << "Passed: " << GREEN << passed << RESET
    << " Failed: " << RED << (_tests.size() - passed) << RESET << std::endl;
}

}
