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
        auto sketchBoard = *board;

        const bool fastComparable = board->isFastComparable();

        heuristic->initSolved(boardSize.first, boardSize.second);

        toProcessSet.emplace(sketchBoard, heuristic->getDistance(sketchBoard));

        while (!toProcessSet.empty()) {
            auto currentNode = toProcessSet.extract(*(--toProcessSet.rend())).value();
            auto &currentBoard = currentNode.first;

            if (currentNode.first.isSolved()) {
                *board = currentNode.first;
                return true;
            }

            bool alreadyProcessed = false;

            if (processedMap.find(currentBoard) != processedMap.end()) {
                alreadyProcessed = true;
                Restructure(currentNode);
            }

            if (!alreadyProcessed) {
                if (currentNode.first.getMoves() < sise::cfg::maxRecursionDepth) {
                    for (auto &direction : addPattern()) {
                        if (currentNode.first.canMove(direction)) {
                            auto copiedNode = currentNode;

                            copiedNode.first.move(direction);
                            copiedNode.second = heuristic->getDistance(copiedNode.first);
                            nVisitedStates++;
                            toProcessSet.insert(copiedNode);
                        }
                    }
                }
                processedMap.insert(std::move(currentNode));
                nProcessedStates++;
            }
        }

        return false;
    }

    void ASTR::Restructure(std::pair<board, int> &newNode) {
        auto processedNode = processedMap.extract(newNode.first);
        processedMap.insert(newNode);
        if (processedNode.key().getMoves() > newNode.first.getMoves()) {
            Throw("Node structure fix was not yet implemented and it is needed");
            // Disturbance in the node structure was introduced - need to fix this
            // trace processed (this never happens with A* algorithm)

            // for all processed -> test all available moves
            //     if node was already there
            //         and you got one that had less moves
            //             replace it with yours
            //             if this node was "processed node" -> trace deeper
            //             else if this node was "visited node" -> don't trace deeper
        }
    }
}
