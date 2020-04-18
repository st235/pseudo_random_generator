#include <fstream>
#include <iostream>
#include <unordered_set>

#include "./src/RandomFactory.h"
#include "./tools/analytics/drawing/Bitmap.h"

int detectCycle(random_generator::Random* random);

int main() {
    auto random_factory = std::make_unique<random_generator::RandomFactory>();
    auto random_ptr = random_factory->create(random_generator::RandomFactory::Type::MIDDLE_SQUARES);

//    std::cout << "Cycle size is: " << detectCycle(random_ptr.get());

    auto bitmap = tools::Bitmap::create("chart", 100, 100);

    auto image_name = bitmap->getTitle() + ".bmp";
    FILE* imageFile = fopen(image_name.c_str(), "wb");

    uint8_t padding[3] = {0, 0, 0};
    int paddingSize = (4 - (bitmap->getWidth() * 3) % 4) % 4;

    bitmap->fillWithColor(0x00FFFFFF);

    bitmap->putPixelAt(1, 1, static_cast<uint32_t>(0));
    bitmap->putPixelAt(5, 5, static_cast<uint32_t>(0));
    bitmap->putPixelAt(50, 50, static_cast<uint32_t>(0));

    fwrite(bitmap->getFileHeader(), 1, tools::Bitmap::getFileHeaderSizeInBytes(), imageFile);
    fwrite(bitmap->getInfoHeader(), 1, tools::Bitmap::getInfoHeaderSizeInBytes(), imageFile);

    for(int i = 0; i < bitmap->getHeight(); i++) {
        fwrite(bitmap->getImageData() + (i * bitmap->getWidth() * 3), 3, bitmap->getWidth(), imageFile);
        fwrite(padding, 1, paddingSize, imageFile);
    }

    for (int i = 0; i < 100; i++) {
        std::cout << "Value: " << random_ptr->next() << std::endl;
    }

    fclose(imageFile);

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
