#include "Histograms.h"

namespace {

struct fuzzy_search: std::unary_function<double, bool> {
    const double _alpha;
    const double _value;

    fuzzy_search(const double alpha, const  double value): _alpha(alpha), _value(value) {
    }

    bool operator()(const double& target) const {
        return abs(target - _value) < _alpha;
    }
};

}

namespace tools {

Histograms::Histograms(uint16_t capacity): _capacity(capacity) {
    double interval_length = getIntervalLength();

    double current = 0.0;
    while (current < 1.0) {
        _intervals.insert(current);
        current += interval_length;
    }
}

void Histograms::countPointAt(double position) {
    const auto& interval_iterator =
            std::find_if(_intervals.begin(), _intervals.end(), fuzzy_search(getIntervalLength(), position));

    if (interval_iterator == _intervals.end()) {
        throw std::runtime_error("cannot find closest value");
    }

    const auto& hit_iterator = _hit_count.find(*interval_iterator);

    uint32_t rawValue = 0;
    if (hit_iterator != _hit_count.end()) {
        rawValue = hit_iterator->second;
    }

    rawValue++;
    _hit_count[*interval_iterator] = rawValue;
}

std::map<double, uint32_t> Histograms::rawHistogram() const {
    std::map<double, uint32_t> temp;
    temp.insert(_hit_count.begin(), _hit_count.end());
    return temp;
}


double Histograms::getIntervalLength() const {
    return 1.0 / static_cast<double>(_capacity);
}

}
