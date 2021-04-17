//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "ASTR.h"
#include "../nonheur/hardPattern.h"

#include <algorithm>
#include <iostream>

namespace sise {

    ASTR::ASTR(const std::string &arg) {
        if (arg == "manh") {
            heuristic = std::make_shared<manhattan>();
        } else if (arg == "hamm") {
            heuristic = std::make_shared<hamming>();
        } else throw exception("Wrong heuristics argument");
    }

    bool ASTR::solve(std::shared_ptr<board> board) {
        sise::hardPattern addPattern("LRUD");

        const auto boardSize = board->size();
        auto sketchBoard = *board;

        heuristic->initSolved(boardSize.first, boardSize.second);

        toProcess.emplace_back(sketchBoard, heuristic->getDistance(sketchBoard));

        while (!toProcess.empty()) {
            SortToProcess();
            auto &currentNode = toProcess.back();

            if (currentNode.first.isSolved()) {
                *board = currentNode.first;
                toProcess.clear();
                processed.clear();
                toProcess.shrink_to_fit();
                processed.shrink_to_fit();
                return true;
            }

            bool alreadyProcessed = false;

            for (auto &processedNode : processed) {
                if (processedNode.first.toString() == currentNode.first.toString()) {
                    alreadyProcessed = true;
                    if (processedNode.first.getMoves() > currentNode.first.getMoves()) {
                        processedNode = currentNode;
                    }
                }
            }

            if (alreadyProcessed) toProcess.pop_back();

            for (auto &direction : addPattern()) {
                
            }
        }

        return false;
    }

    void ASTR::SortToProcess() {
        std::sort(toProcess.begin(), toProcess.end(),
                  [&](const auto &a, const auto &b) {
                      return a.second > b.second;
                  });
    }
}
