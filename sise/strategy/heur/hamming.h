//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 22.03.2021.
//

#ifndef SISE_HAMMING_H
#define SISE_HAMMING_H

#include "heuristics.h"

namespace sise {

    class hamming : public heuristics {
    public:
        int getDistance(board &candidate) override;
    };

}
#endif //SISE_HAMMING_H
