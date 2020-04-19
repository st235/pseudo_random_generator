#ifndef PSEUDO_RANDOM_GENERATOR_CHART_H
#define PSEUDO_RANDOM_GENERATOR_CHART_H

#include <cstdint>

#include "./Bitmap.h"
#include "./Color.h"

namespace tools {

class Chart {
private:
    std::unique_ptr<Bitmap> _bitmap;

public:
    Chart(std::string title, uint16_t width, uint16_t height);
    Chart(const Chart& chart) = delete;
    Chart& operator=(const Chart& chart) = delete;
    Chart(Chart&& chart) noexcept;
    Chart& operator=(Chart&& chart) noexcept;

    void addPoint(uint16_t x, uint16_t y, Color* color);
    Bitmap* getChart();
};

}  // namespace tools

#endif //PSEUDO_RANDOM_GENERATOR_CHART_H
