#ifndef PSEUDO_RANDOM_LINEAR_CONGRUENTIAL_RANDOM_H
#define PSEUDO_RANDOM_LINEAR_CONGRUENTIAL_RANDOM_H

#include <cstdint>
#include <cfloat>

namespace random_generator {

class Random {
public:
   virtual double next() = 0;
   virtual uint32_t nextInt() = 0;

   virtual ~Random() = default;
};

} // namespace random_generator

#endif //PSEUDO_RANDOM_LINEAR_CONGRUENTIAL_RANDOM_H
