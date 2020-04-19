#ifndef PSEUDO_RANDOM_LINEAR_CONGRUENTIAL_RANDOMFACTORY_H
#define PSEUDO_RANDOM_LINEAR_CONGRUENTIAL_RANDOMFACTORY_H

#include <memory>

#include "Random.h"

namespace {

    uint32_t GetCurrentSystemTime();

}

namespace random_generator {

class RandomFactory {
public:
    enum class Type {
        LINEAR_CONGRUENTIAL,
        MIDDLE_SQUARES
    };

    std::unique_ptr<Random> create(Type type = Type::LINEAR_CONGRUENTIAL, uint32_t seed = GetCurrentSystemTime());
};

}  // namespace random_generator

#endif //PSEUDO_RANDOM_LINEAR_CONGRUENTIAL_RANDOMFACTORY_H
