#ifndef PSEUDO_RANDOM_GENERATOR_RENDERER_H
#define PSEUDO_RANDOM_GENERATOR_RENDERER_H

#include <string>

#include "./Bitmap.h"

namespace tools {

class Renderer {
private:
    std::string _filename;
    std::string _extension;

    static std::string DELIMITER_DOT;

public:
    Renderer(std::string filename, std::string extension);
    Renderer(const Renderer& renderer) = delete;
    Renderer& operator=(const Renderer& renderer) = delete;
    Renderer(Renderer&& renderer) noexcept;
    Renderer& operator=(Renderer&& renderer) noexcept;

    std::string getFilename() const;

    void drawBitmap(const Bitmap* bitmap);

    static std::unique_ptr<Renderer> forBitmap(const Bitmap* bitmap);

    static std::string EXT_BMP;
};

}


#endif //PSEUDO_RANDOM_GENERATOR_RENDERER_H
