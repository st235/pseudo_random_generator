#ifndef PSEUDO_RANDOM_GENERATOR_TEST_H
#define PSEUDO_RANDOM_GENERATOR_TEST_H

#include <string>

namespace tests {

class Test {
public:
    enum class Result {
        OK, ERROR
    };

    virtual std::string title() = 0;

    virtual Result run() = 0;
    virtual void saveReport() = 0;

    virtual ~Test() = default;
};

}

#endif //PSEUDO_RANDOM_GENERATOR_TEST_H
