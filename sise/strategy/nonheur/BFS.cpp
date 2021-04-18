//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "BFS.h"

namespace sise {

    BFS::BFS(const std::string &arg) : pattern(arg) {}

    bool BFS::solve(std::shared_ptr<board> board) {
        auto sketchBoard = *board;
        toProcess.emplace_front(sketchBoard, 0);

        while (!toProcess.empty()) {
            auto currentNode = toProcess.front();
            toProcess.pop_front();
            auto &currentBoard = currentNode.first;

            if (currentNode.first.isSolved()) {
                *board = currentNode.first;
                return true;
            }

            bool alreadyProcessed = false;

            if (processedMap.find(currentBoard) != processedMap.end()) {
                alreadyProcessed = true;
                Retrace(currentNode);
            }

            if (!alreadyProcessed) {
                if (currentNode.first.getMoves() < sise::cfg::maxRecursionDepth) {
                    for (auto &direction : pattern()) {
                        if (currentNode.first.canMove(direction)) {
                            auto copiedNode = currentNode;

                            copiedNode.first.move(direction);

                            toProcess.push_back(copiedNode);
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
