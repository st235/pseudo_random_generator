#include "RandomFactory.h"

#include <chrono>
#include "./linear/LinearCongruentialRandom.h"

namespace {

constexpr uint32_t MAX_VALUE = 0xFFFFFFFF;

uint32_t GetCurrentSystemTime() {
    const auto& current_time = std::chrono::system_clock::now();
    const auto& current_timestamp = std::chrono::system_clock::to_time_t(current_time);
    return static_cast<uint32_t>(current_timestamp % MAX_VALUE);
}

}  // anonymous namespace

namespace random_generator {

std::unique_ptr<Random> RandomFactory::create(Type type) {
    switch (type) {
        case Type::LINEAR_CONGRUENTIAL:
            return std::make_unique<LinearCongruentialRandom>(GetCurrentSystemTime());
        default:
            throw std::runtime_error("cannot find suitable algorithm");
    }
}

}  // namespace random_generator
