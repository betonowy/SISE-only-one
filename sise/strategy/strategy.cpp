//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "strategy.h"
#include "nonheur/hardPattern.h"

namespace sise {
    bool NodeLess::operator()(const std::pair<board, int> &a, const std::pair<board, int> &b) const {
        return a.second < b.second;
    }

    size_t NodeHasher::operator()(const board &a) const noexcept {
        auto size = a.size();
        size_t hash = 0;

        for (size_t x = 0; x < size.first; x++)
            for (size_t y = 0; y < size.second; y++)
                hash += a.get(x, y) * ((37 * x) + (y * 43));

        return hash;
    }

    bool NodeEquals::operator()(const board &a, const board &b) const {
        if (a.isFastComparable())
            return board::FastBoardComp16(a, b);

        return a == b;
    }

    void strategy::Retrace(std::pair<board, int> &newNode) {
        sise::hardPattern pattern("LRUD");
        for (auto &processedNode : processedMap) {
            if (newNode.first == processedNode.first) {
                processedMap.erase(processedNode.first);
                processedMap.insert(newNode);
                if (newNode.first.getMoves() < processedNode.first.getMoves()) {
                    for (auto &direction : pattern()) {
                        auto tracedNode = newNode;
                        if (tracedNode.first.canMove(direction)) {
                            tracedNode.first.move(direction);
                            return Retrace(tracedNode);
                        }
                    }
                } else
                    break;
            }
        }
        auto FindInDeck = [&](auto cos) {
            auto iterator = toProcess.begin();
            do {
                if (cos == *iterator) break;
            } while (++iterator != toProcess.end());
            return iterator;
        };
        for (auto &notProcessedNode : toProcess) {
            if (newNode.first == notProcessedNode.first) {
                if(newNode.first.getMoves() < notProcessedNode.first.getMoves()) {
                    auto iterator = FindInDeck(newNode);
                    if (iterator != toProcess.end())
                        *iterator = newNode;
                }
                else
                    break;
            }
        }
    }
}
