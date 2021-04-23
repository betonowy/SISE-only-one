//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_DFS_H
#define SISE_DFS_H

#include "strategy/strategy.h"
#include <stack>

namespace sise {
    class DFS : public strategy {
    public:
        explicit DFS(const std::string& arg);

        bool solve(std::shared_ptr<board> board) override;

    private:
        std::stack<std::pair<board, int>> toProcessStack;
    };

}

#endif //SISE_DFS_H
