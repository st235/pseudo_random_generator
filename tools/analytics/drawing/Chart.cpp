#include "Chart.h"

namespace tools {

Chart::Chart(std::string title, uint16_t width, uint16_t height) {
    _bitmap = Bitmap::create(std::move(title), width * 2, height * 2);
    _bitmap->fillWithColor(&Color::WHITE);
}

Chart::Chart(Chart &&chart) noexcept {
    _bitmap = std::move(chart._bitmap);
}

Chart & Chart::operator=(Chart &&chart) noexcept {
    if (this == &chart) {
        return *this;
    }

    _bitmap.swap(chart._bitmap);

    return *this;
}

void Chart::addPoint(uint16_t x, uint16_t y, Color *color) {
    _bitmap->putPixelAt(x * 2, y * 2, color);
    _bitmap->putPixelAt(x * 2 + 1, y * 2, color);
    _bitmap->putPixelAt(x * 2, y * 2 + 1, color);
    _bitmap->putPixelAt(x * 2 + 1, y * 2 + 1, color);
}

Bitmap* Chart::getChart() {
    return _bitmap.get();
}

}  // namespace tools
