#include <cstdint>

#include "./src/RandomFactory.h"
#include "./tests/histograms/DensityHistogramTest.h"
#include "./tests/histograms/EmpiricalDistributionTest.h"
#include "./tests/plane_distribution/PlaneDistributionTest.h"
#include "./tests/numeric/NumericCharacteristicsTest.h"
#include "./tests/cycle/CycleDetectionTest.h"
#include "./tests/distribution/DistributionTest.h"
#include "./tests/TestRunner.h"

namespace {

constexpr uint32_t SAMPLE_SIZE = 0xFFFF;

}

int main(int argc, char* argv[]) {
    auto random_factory = std::make_unique<random_generator::RandomFactory>();
    auto random_ptr = random_factory->create(random_generator::RandomFactory::Type::LINEAR_CONGRUENTIAL);

    auto test_runner = std::make_unique<tests::TestRunner>(SAMPLE_SIZE, random_ptr.get());

    test_runner
        ->addTest<tests::DensityHistogramTest>()
        ->addTest<tests::EmpiricalDistributionTest>()
        ->addTest<tests::NumericCharacteristicsTest>()
        ->addTest<tests::DistributionTest>()
        ->addTest<tests::PlaneDistributionTest>(512 /* plane capacity */)
        ->addTest<tests::CycleDetectionTest>()
        ->run();

    return 0;
}
