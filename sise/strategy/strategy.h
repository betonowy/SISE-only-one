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

namespace sise {

    struct NodeComparator {
        bool operator()(const std::pair<board, int> &a, const std::pair<board, int> &b) const;
    };

    class strategy {
    public:

        virtual bool solve(std::shared_ptr<board> boardToProcess) = 0;

        [[nodiscard]] inline size_t getProcessedStates() const { return nProcessedStates; }

        [[nodiscard]] inline size_t getVisitedStates() const { return nVisitedStates; }

        static inline size_t getMaxRecursionDepth() { return sise::cfg::maxRecursionDepth; }

    protected:
        std::multiset<std::pair<board, int>, NodeComparator> toProcessSet;
        std::vector<std::pair<board, int>> toProcess;
        std::vector<std::pair<board, int>> processed;

        size_t nVisitedStates;
        size_t nProcessedStates;
    };

}
#endif //SISE_STRATEGY_H
