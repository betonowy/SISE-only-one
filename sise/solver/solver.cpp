//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "solver.h"

#include <utility>
#include <util/timer.h>
#include <util/fileOut.h>

namespace sise {

    solver::solver(std::shared_ptr<board> board, std::shared_ptr<strategy> strategy) :
            strat(std::move(strategy)), boardToSolve(std::move(board)) {

    }

    void solver::solve() {
        sise::timer timer;

        timer.start();

        strat->solve(boardToSolve);

        solveTime = timer.get();
    }

    void solver::saveSolution(const std::string &path) {
        fileOut file(path);

        if (boardToSolve->isSolved()) {
            file.outInt((int) boardToSolve->getMoves());
            file.newLine();
            file.outString(boardToSolve->movesToString());
        } else {
            file.outInt(-1);
        }
    }

    void solver::saveStats(const std::string &path) {
        fileOut file(path);

        if (boardToSolve->isSolved()) {
            file.outInt((int) boardToSolve->getMoves());
        } else {
            file.outInt(-1);
        }

        file.newLine();
        file.outInt((int) strat->getVisitedStates());
        file.newLine();
        file.outInt((int) strat->getProcessedStates());
        file.newLine();
        file.outInt((int) strat->getMaxRecursionDepth());
        file.newLine();
        file.outFloat(solveTime);

    }
}
