#ifndef PSEUDO_RANDOM_GENERATOR_TEST_H
#define PSEUDO_RANDOM_GENERATOR_TEST_H

namespace tests {

class Test {
public:
    virtual Test* run() = 0;
    virtual Test* saveResults() = 0;
};

}

#endif //PSEUDO_RANDOM_GENERATOR_TEST_H
