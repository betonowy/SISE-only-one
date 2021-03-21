//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "strategyFactory.h"

namespace sise {
    std::shared_ptr<strategy> strategyFactory::get(const std::string &arg1, const std::string &arg2) {
        if (arg1 == "bfs") {
            return std::make_shared<BFS>(arg2);
        } else if (arg1 == "dfs") {
            return std::make_shared<DFS>(arg2);
        } else if (arg1 == "astr") {
            return std::make_shared<ASTR>(arg2);
        }

        throw exception("invalid strategy");
    }

}