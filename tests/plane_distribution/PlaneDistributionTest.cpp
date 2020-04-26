#include "PlaneDistributionTest.h"

#include <sstream>
#include <iostream>

#include "../../tools/export/bitmap/Renderer.h"

namespace tests {

PlaneDistributionTest::PlaneDistributionTest(uint16_t dimension, uint32_t sample_size, random_generator::Random *random):
        _dimension(dimension),
        _sample_size(sample_size),
        _random(random) {
    std::stringstream stream;
    stream << "plane_distribution_test " << _dimension;
    _chart = std::make_unique<tools::Chart>(std::move(stream.str()), dimension, dimension);
}

Test* PlaneDistributionTest::run() {
    _current = nextInt();
    for (uint32_t iteration = 0; iteration < _sample_size; iteration++) {
        _previous = _current;
        _current = nextInt();
        _chart->addPoint(_current, _previous, &tools::Color::BLACK);
    }
    return this;
}

Test* PlaneDistributionTest::saveResults() {
    auto renderer = tools::Renderer::forBitmap(_chart->getChart());
    renderer->drawBitmap(_chart->getChart());
    std::cout << "Test flushed at the disk" << std::endl;
    return this;
}

uint16_t PlaneDistributionTest::nextInt() {
    return static_cast<uint16_t>(_random->next() * _dimension);
}


}
