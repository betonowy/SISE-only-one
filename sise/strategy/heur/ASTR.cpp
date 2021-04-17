//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "ASTR.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <list>

namespace sise {

    ASTR::ASTR(const std::string &arg) {
        if (arg == "manh") {
            heuristic = std::make_shared<manhattan>();
        } else if (arg == "hamm") {
            heuristic = std::make_shared<hamming>();
        } else throw exception("Wrong heuristics argument");
    }

    bool ASTR::solve(std::shared_ptr<board> board) {
        const auto boardSize = board->size();
        auto sketchBoard = *board;

        heuristic->initSolved(boardSize.first, boardSize.second);

        toProcess.emplace_back(sketchBoard, heuristic->getDistance(sketchBoard));

        while (!toProcess.empty()) {

        }

        return false;
    }
}
