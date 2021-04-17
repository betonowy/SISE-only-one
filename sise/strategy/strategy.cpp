//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "strategy.h"

namespace sise {
    bool NodeComparator::operator()(const std::pair<board, int> &a, const std::pair<board, int> &b) const {
        return a.second < b.second;
    }
}
