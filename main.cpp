#include <iostream>

#include "./src/RandomFactory.h"

int main() {
    auto random_factory = std::make_unique<random_generator::RandomFactory>();
    auto random_ptr = random_factory->create();

    std::cout << random_ptr->nextInt();

    return 0;
}
