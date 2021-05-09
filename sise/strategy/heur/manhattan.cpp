//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 22.03.2021.
//

#include "manhattan.h"

namespace sise {

    int manhattan::getDistance(board &candidate) {
        int distance = 0;

        size_t maxNumber = candidate.maxNumber();

        for (size_t n = 1; n < maxNumber; n++) {
            auto coordA = candidate.getIndexOf(n);
            auto coordB = solved->getIndexOf(n);

            distance += abs(coordA.first - coordB.first);
            distance += abs(coordA.second - coordB.second);
        }

        return distance + int(candidate.getMoves());
    }
}
