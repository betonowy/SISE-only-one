//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "strategy.h"

namespace sise {

    void strategy::visitState(const std::shared_ptr<board> &state) {
        visitedStates[state->toString()] = true;
    }

    bool strategy::wasVisited(const std::shared_ptr<board> &state) {
        return visitedStates[state->toString()];
    }
}
