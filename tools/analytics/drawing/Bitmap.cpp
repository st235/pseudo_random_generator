#include "Bitmap.h"

namespace {

constexpr uint32_t BYTES_PER_PIXEL = 3;
constexpr uint32_t FILE_HEADER_SIZE_IN_BYTES = 14;
constexpr uint32_t INFO_HEADER_SIZE_IN_BYTES = 40;

}  // anonymous namespace

namespace tools {

Bitmap::Bitmap(std::string&& title,
        uint16_t width,
        uint16_t height): _title(title), _width(width), _height(height) {
    _paddingSize = (4 - (_width * BYTES_PER_PIXEL) % 4) % 4;
    _image_data = new uint8_t[_width * _height * BYTES_PER_PIXEL];
}

uint32_t Bitmap::calculateFileSize() const {
    return FILE_HEADER_SIZE_IN_BYTES + INFO_HEADER_SIZE_IN_BYTES + (BYTES_PER_PIXEL * _width + _paddingSize) * _height;
}

uint16_t Bitmap::getWidth() const {
    return _width;
}

uint16_t Bitmap::getHeight() const {
    return _height;
}

std::string Bitmap::getTitle() const {
    return _title;
}

uint8_t* Bitmap::getFileHeader() const {
    auto* file_header = new uint8_t[] {
            0, 0,         // signature
            0, 0, 0, 0,   // image file size in bytes
            0, 0, 0, 0,   // reserved
            0, 0, 0, 0    // start of pixel array
    };

    uint32_t file_size = calculateFileSize();

    file_header[ 0] = static_cast<uint8_t>('B');
    file_header[ 1] = static_cast<uint8_t>('M');
    file_header[ 2] = static_cast<uint8_t>(file_size);
    file_header[ 3] = static_cast<uint8_t>(file_size >> 8U);
    file_header[ 4] = static_cast<uint8_t>(file_size >> 16U);
    file_header[ 5] = static_cast<uint8_t>(file_size >> 24U);
    file_header[10] = static_cast<uint8_t>(FILE_HEADER_SIZE_IN_BYTES + INFO_HEADER_SIZE_IN_BYTES);

    return file_header;
}

uint8_t* Bitmap::getInfoHeader() const {
    auto* info_header = new uint8_t[] {
            0,0,0,0, // header size
            0,0,0,0, // image width
            0,0,0,0, // image height
            0,0,     // number of color planes
            0,0,     // bits per pixel
            0,0,0,0, // compression
            0,0,0,0, // image size
            0,0,0,0, // horizontal resolution
            0,0,0,0, // vertical resolution
            0,0,0,0, // colors in color table
            0,0,0,0, // important color count
    };

    info_header[ 0] = static_cast<uint8_t>(INFO_HEADER_SIZE_IN_BYTES);
    info_header[ 4] = static_cast<uint8_t>(_width);
    info_header[ 5] = static_cast<uint8_t>(_width >> 8U);
    info_header[ 6] = static_cast<uint8_t>(_width >> 16U);
    info_header[ 7] = static_cast<uint8_t>(_width >> 24U);
    info_header[ 8] = static_cast<uint8_t>(_height);
    info_header[ 9] = static_cast<uint8_t>(_height >> 8U);
    info_header[10] = static_cast<uint8_t>(_height >> 16U);
    info_header[11] = static_cast<uint8_t>(_height >> 24U);
    info_header[12] = static_cast<uint8_t>(1);
    info_header[14] = static_cast<uint8_t>(BYTES_PER_PIXEL * 8);

    return info_header;
}

uint8_t* Bitmap::getImageData() const {
    return _image_data;
}

void Bitmap::fillWithColor(uint32_t color) {
    for (int i = 0; i < _width; i++) {
        for (int j = 0; j < _height; j++) {
            putPixelAt(i, j, color);
        }
    }
}

void Bitmap::putPixelAt(uint32_t x, uint32_t y, uint32_t color) {
    _image_data[y * _width * BYTES_PER_PIXEL + x * BYTES_PER_PIXEL] = static_cast<uint8_t>(color);
    _image_data[y * _width * BYTES_PER_PIXEL + x * BYTES_PER_PIXEL + 1] = static_cast<uint8_t>(color >> 8U);
    _image_data[y * _width * BYTES_PER_PIXEL + x * BYTES_PER_PIXEL + 2] = static_cast<uint8_t>(color >> 16U);
}

std::unique_ptr<Bitmap> Bitmap::create(std::string&& title, uint16_t width, uint16_t height) {
    return std::make_unique<Bitmap>(std::move(title), width, height);
}

uint8_t Bitmap::getFileHeaderSizeInBytes() {
    return static_cast<uint8_t>(FILE_HEADER_SIZE_IN_BYTES);
}

uint8_t Bitmap::getInfoHeaderSizeInBytes() {
    return static_cast<uint8_t>(INFO_HEADER_SIZE_IN_BYTES);
}

Bitmap::~Bitmap() {
    delete[] _image_data;
}

}  // namespace tools
