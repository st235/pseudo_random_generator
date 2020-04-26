#include <cstdint>

#include "./src/RandomFactory.h"
#include "./tests/histograms/DensityHistogramTest.h"
#include "./tests/histograms/EmpiricalDistributionTest.h"
#include "./tests/plane_distribution/PlaneDistributionTest.h"

namespace {

constexpr uint32_t SAMPLE_SIZE = 0xFFFF;

}

int main() {
    auto random_factory = std::make_unique<random_generator::RandomFactory>();
    auto random_ptr = random_factory->create(random_generator::RandomFactory::Type::LINEAR_CONGRUENTIAL);

    auto plane_test = std::make_unique<tests::PlaneDistributionTest>(512, SAMPLE_SIZE, random_ptr.get());
    auto density_test = std::make_unique<tests::DensityHistogramTest>(SAMPLE_SIZE, random_ptr.get());
    auto empirical_distribution_test = std::make_unique<tests::EmpiricalDistributionTest>(SAMPLE_SIZE, random_ptr.get());

    plane_test
        ->run()
        ->saveResults();

    density_test
        ->run()
        ->saveResults();

    empirical_distribution_test
        ->run()
        ->saveResults();

    return 0;
}
