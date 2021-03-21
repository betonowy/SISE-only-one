//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "hardPattern.h"

namespace sise {

    hardPattern::hardPattern(const std::string &arg) {
        if (arg.size() != 4) throw exception("pattern string is wrong");

        for (size_t i = 0; i < pattern.size(); i++)
            pattern[i] = board::charToMove(arg[i]);
    }
}
