#include "LinearCongruentialRandom.h"

namespace {

/**
 * Maximum available boundary for unsigned 32 bit integer.
 */
constexpr uint32_t MAX_VALUE = 0xFFFFFFFF;

/**
 * Default value for increment, if it will be absent
 * Prime number, which is coprime to {MAX_VALUE}
 */
constexpr uint32_t DEFAULT_INCREMENT = 514229;

/**
 * Default value for multiplier, if it will be absent
 * Not a prime number, but {DEFAULT_MULTIPLIER} - 1 multiple to 4
 */
constexpr uint32_t DEFAULT_MULTIPLIER = 39717;

}  // anonymous namespace

namespace random_generator {

LinearCongruentialRandom::LinearCongruentialRandom(uint32_t seed): _seed(seed),
                                                                   _multiplier(DEFAULT_MULTIPLIER),
                                                                   _increment(DEFAULT_INCREMENT),
                                                                   _modulus(MAX_VALUE) {
    // empty on purpose
}

LinearCongruentialRandom::LinearCongruentialRandom(
        uint32_t seed,
        uint32_t multiplier,
        uint32_t increment): _seed(seed), _multiplier(multiplier), _increment(increment), _modulus(MAX_VALUE) {
    // empty on purpose
}

LinearCongruentialRandom::LinearCongruentialRandom(
        uint32_t seed,
        uint32_t multiplier,
        uint32_t increment,
        uint32_t modulus): _seed(seed), _multiplier(multiplier), _increment(increment), _modulus(modulus) {
    // empty on purpose
}

double LinearCongruentialRandom::next() {
    return static_cast<double>(nextInt()) / MAX_VALUE;
}

uint32_t LinearCongruentialRandom::nextInt() {
    return (_seed = (_multiplier * _seed + _increment) % _modulus);
}

};  // namespace random_generator
