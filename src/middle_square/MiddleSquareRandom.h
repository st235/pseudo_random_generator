#ifndef PSEUDO_RANDOM_GENERATOR_MIDDLESQUARERANDOM_H
#define PSEUDO_RANDOM_GENERATOR_MIDDLESQUARERANDOM_H

#include "../Random.h"

namespace random_generator {

class MiddleSquareRandom: public Random {
private:
    uint32_t _seed;

public:
    MiddleSquareRandom(uint32_t seed);

    double next() override;

    uint32_t nextInt() override;

    ~MiddleSquareRandom() override = default;
};

}  // namespace random_generator

#endif //PSEUDO_RANDOM_GENERATOR_MIDDLESQUARERANDOM_H
