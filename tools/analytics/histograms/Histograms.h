#ifndef PSEUDO_RANDOM_GENERATOR_HISTOGRAMS_H
#define PSEUDO_RANDOM_GENERATOR_HISTOGRAMS_H

#include <cstdint>
#include <memory>
#include <set>
#include <map>
#include <unordered_map>

namespace tools {

/*
 * Normalized histogram generator
 * at [0..1]
 */
class Histograms {
private:
  uint16_t _capacity;
  std::set<double> _intervals;
  std::unordered_map<double, uint32_t> _hit_count;
  uint64_t _count;

public:
    Histograms(uint16_t capacity);
    /**
     * O(lgn n) complexity
     * @param position normalized double value inside of [0..1] range
     */
    void countPointAt(double position);

    /**
     * O(n lgn) complexity, where n is the capacity
     * @return
     */
    std::map<double, uint32_t> rawHistogram() const;

    uint64_t getCount() const;

    double getIntervalLength() const;
};

}

#endif //PSEUDO_RANDOM_GENERATOR_HISTOGRAMS_H
