//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 22.03.2021.
//

#include <iostream>
#include <iomanip>
#include "heuristics.h"

namespace sise {

    void heuristics::initSolved(size_t sizeX, size_t sizeY) {
        solved = std::make_unique<board>(sizeX, sizeY, true);
    }

    void heuristics::printScoreForMove(moveDirection move, int score) {
        std::cout << "move: " << std::setw(10);
        switch (move) {
            case MOVE_UP:
                std::cout << "up";
                break;
            case MOVE_RIGHT:
                std::cout << "right";
                break;
            case MOVE_DOWN:
                std::cout << "down";
                break;
            case MOVE_LEFT:
                std::cout << "left";
                break;
        }
        std::cout << std::setw(5) << score << std::endl;
    }

}