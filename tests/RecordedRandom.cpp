#include "RecordedRandom.h"

namespace tests {

RecordedRandom::RecordedRandom(uint32_t sample_size, random_generator::Random* random):
    _sample_size(sample_size),
    _random(random),
    _current_iteration(0) {

    for (uint64_t i = 0; i < _sample_size; i++) {
        _samples.push_back(_random->next());
    }
}

double RecordedRandom::next() {
    return _samples[_current_iteration];
}

uint32_t RecordedRandom::nextInt() {
    return _samples[_current_iteration] * 0xFFFFFFFF;
}

void RecordedRandom::flush() {
    _current_iteration = 0;
}

std::unique_ptr<RecordedRandom> RecordedRandom::wrap(uint32_t sample_size, random_generator::Random *random) {
    return std::make_unique<RecordedRandom>(sample_size, random);
}

}
