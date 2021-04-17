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
                toProcessSet.clear();
                processed.clear();
                processed.shrink_to_fit();
                return true;
            }

            bool alreadyProcessed = false;

            if (fastComparable) {
                for (auto &processedNode : processed) {
                    auto &processedBoard = processedNode.first;
                    if (board::FastBoardComp16(processedBoard, currentBoard)) {
                        alreadyProcessed = true;
                        Restructure(processedNode, currentNode);
                    }
                }
            } else {
                for (auto &processedNode : processed) {
                    auto &processedBoard = processedNode.first;
                    if (processedBoard == currentBoard) {
                        alreadyProcessed = true;
                        Restructure(processedNode, currentNode);
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
                            toProcessSet.insert(copiedNode);
                        }
                    }
                }

                processed.push_back(std::move(currentNode));
                nProcessedStates++;
            }
        }

        return false;
    }

    void ASTR::Restructure(std::pair<board, int> &startNode, std::pair<board, int> &newNode) {
        if (startNode.first.getMoves() > newNode.first.getMoves()) {
            startNode = newNode;
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
