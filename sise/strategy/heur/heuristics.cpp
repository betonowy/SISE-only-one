//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 22.03.2021.
//

#include <iostream>
#include <iomanip>
#include "heuristics.h"

namespace sise {

    void heuristics::initSolved(size_t sizeX, size_t sizeY) {
        solved = std::make_unique<board>(sizeX, sizeY, true);
    }

}