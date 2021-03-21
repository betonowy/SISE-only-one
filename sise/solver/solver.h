//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_SOLVER_H
#define SISE_SOLVER_H

#include <board/board.h>
#include <strategy/strategy.h>
#include <memory>
#include <unordered_map>

namespace sise {
    class solver {
    public:
        solver(std::shared_ptr<board> board, std::shared_ptr<strategy> strategy);

        void solve();

        void saveSolution(const std::string &path);

        void saveStats(const std::string &path);

    private:
        std::shared_ptr<strategy> strat;
        std::shared_ptr<board> boardToSolve;

        double solveTime = 0;

    };

}

#endif //SISE_SOLVER_H
