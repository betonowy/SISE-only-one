//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_STRATEGY_H
#define SISE_STRATEGY_H

#include <board/board.h>
#include <headerConfig.h>
#include <memory>
#include <list>
#include <unordered_map>
#include <set>
#include <deque>

namespace sise {

    struct NodeLess {
        bool operator()(const std::pair<board, int> &a, const std::pair<board, int> &b) const;
    };

    struct NodeHash {
        size_t operator()(const board &a) const noexcept;
    };

    struct NodeEquals {
        bool operator()(const board &a, const board &b) const;
    };

    class strategy {
    public:

        virtual bool solve(std::shared_ptr<board> boardToProcess) = 0;

        [[nodiscard]] inline size_t getProcessedStates() const { return nProcessedStates; }

        [[nodiscard]] inline size_t getVisitedStates() const { return nVisitedStates; }

        [[nodiscard]] inline size_t getMaxRecursionDepth() const { return maxRecursionDepth; }

    protected:
        std::unordered_map<board, int, NodeHash, NodeEquals> processedMap;

        size_t nVisitedStates = 0;
        size_t nProcessedStates = 0;
        size_t maxRecursionDepth = 0;
    };

}
#endif //SISE_STRATEGY_H
