//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "BFS.h"

namespace sise {

    BFS::BFS(const std::string &arg) : strategy(arg) {}

    bool BFS::solve(std::shared_ptr<board> board) {
        toProcessQueue.emplace(*board, 0);

        while (!toProcessQueue.empty()) {
            auto currentNode = toProcessQueue.front();
            toProcessQueue.pop();
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

                            toProcessQueue.push(std::move(copiedNode));
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
