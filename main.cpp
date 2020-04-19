#include <iostream>
#include <unordered_set>

#include "./src/RandomFactory.h"
#include "./tools/analytics/drawing/Chart.h"
#include "./tools/analytics/drawing/Color.h"
#include "./tools/analytics/drawing/Renderer.h"

int detectCycle(random_generator::Random* random);

int main() {
    auto random_factory = std::make_unique<random_generator::RandomFactory>();
    auto chart = std::make_unique<tools::Chart>("middle_squares", 200, 200);
    auto renderer = tools::Renderer::forBitmap(chart->getChart());

    uint32_t v = 2355512;
    for (uint16_t i = 0; i < 200; i++) {
        auto random_ptr = random_factory->create(random_generator::RandomFactory::Type::MIDDLE_SQUARES, v++);

        for (int j = 0; j < 100; j++) {
            int point = static_cast<uint16_t>(random_ptr->next() * 200);
            std::cout << point << std::endl;
            chart->addPoint(point, i, &tools::Color::BLACK);
        }
    }

    renderer->drawBitmap(chart->getChart());

    return 0;
}

int detectCycle(random_generator::Random* random) {
    std::unordered_set<uint32_t> lookup;
    uint32_t current_value = random->nextInt();
    while (lookup.find(current_value) == lookup.end()) {
        lookup.insert(current_value);
        current_value = random->nextInt();
    }
    return lookup.size();
}
