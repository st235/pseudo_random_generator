#include "RandomFactory.h"

#include <chrono>
#include "./linear/LinearCongruentialRandom.h"
#include "./middle_square/MiddleSquareRandom.h"

namespace {

constexpr uint32_t MAX_VALUE = 0xFFFFFFFF;

}  // anonymous namespace

namespace random_generator {

uint32_t GetCurrentSystemTime() {
    const auto& current_time = std::chrono::system_clock::now();
    const auto& current_timestamp = std::chrono::system_clock::to_time_t(current_time);
    return static_cast<uint32_t>(current_timestamp % MAX_VALUE);
}

std::unique_ptr<Random> RandomFactory::create(Type type, uint32_t seed) {
    switch (type) {
        case Type::LINEAR_CONGRUENTIAL:
            return std::make_unique<LinearCongruentialRandom>(seed);
        case Type::MIDDLE_SQUARES:
            return std::make_unique<MiddleSquareRandom>(seed);
        default:
            throw std::runtime_error("cannot find suitable algorithm");
    }
}

}  // namespace random_generator
