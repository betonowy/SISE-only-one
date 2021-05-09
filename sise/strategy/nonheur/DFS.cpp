//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "DFS.h"

namespace sise {

    DFS::DFS(const std::string &arg) : strategy(arg) {}

    bool DFS::solve(std::shared_ptr<board> board) {
        toProcessStack.emplace(*board, 0);

        while (!toProcessStack.empty()) {
            auto currentNode = toProcessStack.top();
            toProcessStack.pop();

            maxRecursionDepth = std::max(maxRecursionDepth, currentNode.first.getMoves());

            if (currentNode.first.isSolved()) {
                *board = currentNode.first;
                return true;
            }

            bool alreadyProcessed = false;
            auto processedNode = processedMap.find(currentNode.first);

            if (processedNode != processedMap.end() && processedNode->first.getMoves() < currentNode.first.getMoves()) {
                alreadyProcessed = true;
                processedMap.erase(processedNode->first);
                processedMap.insert(currentNode);
            }

            if (!alreadyProcessed) {
                if (currentNode.first.getMoves() < sise::cfg::maxRecursionDepth) {
                    for (auto &direction : pattern.Reversed()) { // stack workaround
                        if (currentNode.first.canMove(direction)) {
                            auto copiedNode = currentNode;

                            copiedNode.first.move(direction);

                            toProcessStack.push(std::move(copiedNode));
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
