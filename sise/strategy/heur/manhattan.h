//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 22.03.2021.
//

#ifndef SISE_MANHATTAN_H
#define SISE_MANHATTAN_H

#include "heuristics.h"

namespace sise {
    class manhattan : public heuristics {
    public:
        int getDistance(board &candidate) override;
    };

}

#endif //SISE_MANHATTAN_H
