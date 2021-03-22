//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "ASTR.h"

#include <algorithm>
#include <climits>
#include <iostream>

namespace sise {

    ASTR::ASTR(const std::string &arg) {
        if (arg == "manh") {
            heuristic = std::make_shared<manhattan>();
        } else if (arg == "hamm") {
            heuristic = std::make_shared<hamming>();
        } else throw exception("Wrong heuristics argument");
    }

    bool ASTR::solve(std::shared_ptr<board> board) {
        const auto boardSize = board->size();
        auto sketchBoard = *board;

        auto movePossibilityCheck = [&](moveDirection move) {
            if (!board->canMove(move)) return true;

            sketchBoard = *board;
            sketchBoard.move(move);

            if (visitedStates[sketchBoard.toString()]) return true;

            return false;
        };

        heuristic->initSolved(boardSize.first, boardSize.second);

        std::vector<moveDirection> possibleMoves;
        std::vector<size_t> scoreArray;

        while (!board->isSolved()) {
            possibleMoves = {MOVE_UP, MOVE_RIGHT, MOVE_DOWN, MOVE_LEFT};


            possibleMoves.erase(std::remove_if(possibleMoves.begin(), possibleMoves.end(),
                                               movePossibilityCheck), possibleMoves.end());

            if (possibleMoves.empty()) return false;

            std::cout << std::endl;

            moveDirection bestMove;
            int lowestScore = INT_MAX;

            for (auto &move : possibleMoves) {
                sketchBoard = *board;

                sketchBoard.move(move);
                int score = heuristic->getDistance(sketchBoard);
                nProcessedStates++;
                if (score < lowestScore) {
                    lowestScore = score;
                    bestMove = move;
                }
            }

            board->move(bestMove);
            visitedStates[board->toString()] = true;
            nVisitedStates++;
        }

        return true;
    }
}
