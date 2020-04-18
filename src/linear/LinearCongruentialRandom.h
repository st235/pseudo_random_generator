#ifndef PSEUDO_RANDOM_LINEAR_CONGRUENTIAL_LINEARCONGRUENTIALRANDOM_H
#define PSEUDO_RANDOM_LINEAR_CONGRUENTIAL_LINEARCONGRUENTIALRANDOM_H

#include "../Random.h"

namespace random_generator {

/**
 * Linear congruential random generator uses the following
 * algorithm for each next state
 * X_{n+1} = (aX_{n}+c) mod m
 */
class LinearCongruentialRandom: public Random {
private:
    /**
     * initialization vector aka X_{0}
     * stores current state during runtime
     */
    uint32_t _seed;

    /**
     * alias for a
     */
    uint32_t _multiplier;

    /**
     * alias for c
     */
    uint32_t _increment;

    /**
     * alias for m
     */
    uint32_t _modulus;

public:
    LinearCongruentialRandom(uint32_t seed);

    LinearCongruentialRandom(uint32_t seed, uint32_t multiplier, uint32_t increment);

    LinearCongruentialRandom(uint32_t seed, uint32_t multiplier, uint32_t increment, uint32_t modulus);

    double next() override;

    uint32_t nextInt() override;

    ~LinearCongruentialRandom() override = default;
};

};  // namespace random_generator

#endif //PSEUDO_RANDOM_LINEAR_CONGRUENTIAL_LINEARCONGRUENTIALRANDOM_H
