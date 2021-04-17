//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 22.03.2021.
//

#ifndef SISE_HEURISTICS_H
#define SISE_HEURISTICS_H

#include <board/board.h>
#include <memory>

namespace sise {
    class heuristics {
    public:
        void initSolved(size_t sizeX, size_t sizeY);

        virtual int getDistance(board &board) = 0;

    protected:
        std::unique_ptr<board> solved;
    };

}

#endif //SISE_HEURISTICS_H
