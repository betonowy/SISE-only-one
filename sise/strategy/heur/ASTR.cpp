//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "ASTR.h"
#include "../nonheur/hardPattern.h"

#include <algorithm>


namespace sise {

    ASTR::ASTR(const std::string &arg) {
        if (arg == "manh") {
            heuristic = std::make_shared<manhattan>();
        } else if (arg == "hamm") {
            heuristic = std::make_shared<hamming>();
        } else Throw("Wrong heuristics argument");
    }

    bool ASTR::solve(std::shared_ptr<board> board) {
        sise::hardPattern addPattern("LRUD");

        const auto boardSize = board->size();
        heuristic->initSolved(boardSize.first, boardSize.second);
        toProcessSet.emplace(*board, heuristic->getDistance(*board));

        while (!toProcessSet.empty()) {
            auto currentNode = toProcessSet.extract(*(--toProcessSet.rend())).value();
            auto &currentBoard = currentNode.first;

            maxRecursionDepth = std::max(maxRecursionDepth, currentBoard.getMoves());

            if (currentNode.first.isSolved()) {
                *board = currentNode.first;
                return true;
            }

            if (processedMap.find(currentBoard) == processedMap.end()) {
                if (currentNode.first.getMoves() < sise::cfg::maxRecursionDepth) {
                    for (auto &direction : addPattern()) {
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
