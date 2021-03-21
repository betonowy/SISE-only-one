//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_BFS_H
#define SISE_BFS_H

#include "strategy/strategy.h"
#include "hardPattern.h"

namespace sise {
    class BFS : public strategy {
    public:
        explicit BFS(const std::string& arg);

        bool solve(std::shared_ptr<board> board) override;

    private:
        hardPattern pattern;
    };

}

#endif //SISE_BFS_H
