#ifndef PSEUDO_RANDOM_FISH_RANDOMFACTORY_H
#define PSEUDO_RANDOM_FISH_RANDOMFACTORY_H

#include <memory>

#include "Random.h"

namespace random_generator {

class RandomFactory {
public:
    enum class Type {
        LINEAR_CONGRUENTIAL
    };

    std::unique_ptr<Random> create(Type type = Type::LINEAR_CONGRUENTIAL);
};

}  // namespace random_generator

#endif //PSEUDO_RANDOM_FISH_RANDOMFACTORY_H
