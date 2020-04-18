#ifndef PSEUDO_RANDOM_GENERATOR_BITMAP_H
#define PSEUDO_RANDOM_GENERATOR_BITMAP_H

#include <string>
#include <memory>

namespace tools {

class Bitmap {
private:
    std::string _title;
    uint16_t _width;
    uint16_t _height;
    uint32_t _paddingSize;

    uint8_t* _image_data;

    uint32_t calculateFileSize() const;

public:
    Bitmap(std::string&& title, uint16_t width, uint16_t height);

    std::string getTitle() const;

    uint16_t getWidth() const;

    uint16_t getHeight() const;

    uint8_t* getFileHeader() const;

    uint8_t* getInfoHeader() const;

    uint8_t* getImageData() const;

    // color in format 00000000rrrrrrrrggggggggbbbbbbbb
    void putPixelAt(uint32_t x, uint32_t y, uint32_t color);

    ~Bitmap();

    static std::unique_ptr<Bitmap> create(std::string&& title, uint16_t width, uint16_t height);

    static uint8_t getFileHeaderSizeInBytes();

    static uint8_t getInfoHeaderSizeInBytes();
};

}  // namespace tools


#endif //PSEUDO_RANDOM_GENERATOR_BITMAP_H
