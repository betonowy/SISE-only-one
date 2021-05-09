//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 22.03.2021.
//

#include "hamming.h"

namespace sise {

    int hamming::getDistance(board &candidate) {
        int distance = 0;

        const auto size = candidate.size();

        for (size_t x = 0; x < size.first; x++) {
            for (size_t y = 0; y < size.second; y++) {
                auto &a = candidate.get(x, y);
                auto &b = solved->get(x, y);
                if ((a != b ) && (a != 0)) distance++;
            }
        }

        return distance + int(candidate.getMoves());
    }
}