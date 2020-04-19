#include <iostream>
#include <unordered_set>

#include "./src/RandomFactory.h"
#include "./src/middle_square/MiddleSquareRandom.h"
#include "./tools/analytics/drawing/Chart.h"
#include "./tools/analytics/drawing/Color.h"
#include "./tools/analytics/drawing/Renderer.h"

int detectCycle(random_generator::Random* random);

int main() {

    auto chart = std::make_unique<tools::Chart>("middle_squares", 100, 100);
    auto renderer = tools::Renderer::forBitmap(chart->getChart());

    uint32_t v = 2355512;
    for (uint16_t i = 0; i < 100; i++) {
        auto random_ptr = std::make_unique<random_generator::MiddleSquareRandom>(v++);

        for (int j = 0; j < 100; j++) {
            int point = static_cast<uint16_t>(random_ptr->next() * 100);
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
