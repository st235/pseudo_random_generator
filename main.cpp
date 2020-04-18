#include <iostream>
#include <unordered_set>

#include "./src/RandomFactory.h"

int detectCycle(random_generator::Random* random);

int main() {
    auto random_factory = std::make_unique<random_generator::RandomFactory>();
    auto random_ptr = random_factory->create();

    std::cout << "Cycle size is: " << detectCycle(random_ptr.get());

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
