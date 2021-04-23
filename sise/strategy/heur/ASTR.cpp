//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "ASTR.h"
#include "strategy/hardPattern.h"

#include <algorithm>


namespace sise {

    ASTR::ASTR(const std::string &arg) : strategy("LUDR") {
        if (arg == "manh") heuristic = std::make_shared<manhattan>();
        else if (arg == "hamm") heuristic = std::make_shared<hamming>();
        else Throw("Wrong heuristics argument");
    }

    bool ASTR::solve(std::shared_ptr<board> board) {
        const auto boardSize = board->size();
        heuristic->initSolved(boardSize.first, boardSize.second);
        toProcessSet.emplace(*board, heuristic->getDistance(*board));

        while (!toProcessSet.empty()) {
            auto currentNode = toProcessSet.extract(*(--toProcessSet.rend())).value();
            maxRecursionDepth = std::max(maxRecursionDepth, currentNode.first.getMoves());

            if (currentNode.first.isSolved()) {
                *board = currentNode.first;
                return true;
            }

            if (processedMap.find(currentNode.first) == processedMap.end()) {
                if (currentNode.first.getMoves() < sise::cfg::maxRecursionDepth) {
                    for (auto &direction : pattern()) {
                        if (currentNode.first.canMove(direction)) {
                            auto copiedNode = currentNode;

                            copiedNode.first.move(direction);
                            copiedNode.second = heuristic->getDistance(copiedNode.first);

                            toProcessSet.insert(std::move(copiedNode));
                            nVisitedStates++;
                        }
                    }
                }

                processedMap.insert(std::move(currentNode));
                nProcessedStates++;
            }
        }

        return false;
    }
}
