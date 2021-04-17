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

            auto currentNode = std::move(toProcess.back());
            toProcess.pop_back();

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
                auto &processedBoard = processedNode.first;

                if (processedBoard.toString() == currentNode.first.toString()) {
                    alreadyProcessed = true;

                    if (processedBoard.getMoves() > currentNode.first.getMoves()) {
                        processedNode = currentNode;
                        // Disturbance in the node structure was introduced - need to fix this
                        // trace processed (this never happens with A* algorithm)

                        // for all processed and visited nodes -> test all available moves
                        //     if node was already there
                        //         and you got one that had less moves
                        //             replace it with yours
                        //             if this node was "processed node" -> trace deeper
                        //             else if this node was "visited node" -> dont trace deeper
                    }
                }
            }

            if (!alreadyProcessed) {
                if (currentNode.first.getMoves() < sise::cfg::maxRecursionDepth) {
                    for (auto &direction : addPattern()) {
                        if (currentNode.first.canMove(direction)) {
                            auto copiedNode = currentNode;

                            copiedNode.first.move(direction);
                            copiedNode.second = heuristic->getDistance(copiedNode.first);
                            nVisitedStates++;
                            toProcess.push_back(copiedNode);
                        }
                    }
                }

                processed.push_back(std::move(currentNode));
                nProcessedStates++;
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
