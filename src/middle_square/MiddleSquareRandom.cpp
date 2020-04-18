#include "MiddleSquareRandom.h"

namespace {

constexpr uint32_t MAX_VALUE = 0xFFFFFFFF;
constexpr uint32_t DEFAULT_TYPE_OFFSET = 0x00000010;

}  // anonymous namespace

namespace random_generator {

MiddleSquareRandom::MiddleSquareRandom(uint32_t seed): _seed(seed) {
    // empty on purpose
}

double MiddleSquareRandom::next() {
    return static_cast<double>(nextInt()) / MAX_VALUE;
}

uint32_t MiddleSquareRandom::nextInt() {
    uint64_t squared_value = static_cast<uint64_t>(_seed) * static_cast<uint64_t>(_seed);
    squared_value = squared_value <<  DEFAULT_TYPE_OFFSET; // sixteen bits to right
    squared_value = squared_value >> DEFAULT_TYPE_OFFSET; // to original offset with leaded left zeros
    squared_value = squared_value >> DEFAULT_TYPE_OFFSET; // keep only thirty two bits
    _seed = static_cast<uint32_t>(squared_value);
    return _seed;
}

}  // namespace random_generator
