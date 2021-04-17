//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "strategy.h"

namespace sise {
    bool NodeLess::operator()(const std::pair<board, int> &a, const std::pair<board, int> &b) const {
        return a.second < b.second;
    }

    size_t NodeHasher::operator()(const board &a) const noexcept {
        auto size = a.size();
        size_t hash = 0;

        for (size_t x = 0; x < size.first; x++)
            for (size_t y = 0; y < size.second; y++)
                hash += a.get(x, y) * ((37 * x) + (y * 43));

        return hash;
    }

    bool NodeEquals::operator()(const board &a, const board &b) const {
        if (a.isFastComparable()) {
            return board::FastBoardComp16(a, b);
        } else {
            return a == b;
        }
    }
}
