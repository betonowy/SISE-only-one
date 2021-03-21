//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_DFS_H
#define SISE_DFS_H

#include "strategy/strategy.h"
#include "hardPattern.h"

namespace sise {
    class DFS : public strategy {
    public:
        explicit DFS(const std::string& arg);

        bool solve(std::shared_ptr<board> board) override;

    private:
        hardPattern pattern;
    };

}

#endif //SISE_DFS_H
