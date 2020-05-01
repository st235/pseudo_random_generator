#ifndef PSEUDO_RANDOM_GENERATOR_RECORDEDRANDOM_H
#define PSEUDO_RANDOM_GENERATOR_RECORDEDRANDOM_H

#include "cstdint"
#include <vector>

#include "../src/Random.h"

namespace tests {

class RecordedRandom: random_generator::Random {
private:
    uint32_t _sample_size;
    random_generator::Random* _random;

    uint64_t _current_iteration;
    std::vector<double> _samples;

public:
    RecordedRandom(uint32_t sample_size, random_generator::Random* random);

    double next() override;
    uint32_t nextInt() override;

    void flush();
};

}


#endif //PSEUDO_RANDOM_GENERATOR_RECORDEDRANDOM_H
