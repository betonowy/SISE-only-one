//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_STRATEGY_H
#define SISE_STRATEGY_H

#include <board/board.h>
#include <headerConfig.h>
#include <memory>
#include <unordered_map>

namespace sise {

    class strategy {
    public:

        virtual bool solve(std::shared_ptr<board> board) = 0;

        inline size_t getProcessedStates() const { return nProcessedStates; }

        inline size_t getVisitedStates() const { return nVisitedStates; }

        static inline size_t getMaxRecursionDepth() { return sise::cfg::maxRecursionDepth; }

    private:
        std::unordered_map<std::string, bool> visitedStates;

        size_t nVisitedStates;
        size_t nProcessedStates;
    };

}
#endif //SISE_STRATEGY_H
