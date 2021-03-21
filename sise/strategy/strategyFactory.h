//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_STRATEGYFACTORY_H
#define SISE_STRATEGYFACTORY_H

#include <string>
#include "strategy.h"
#include "nonheur/DFS.h"
#include "nonheur/BFS.h"
#include "heur/ASTR.h"

namespace sise {

    class strategyFactory {
    public:
        static std::shared_ptr<strategy> get(const std::string& arg1, const std::string& arg2);
    };

}

#endif //SISE_STRATEGYFACTORY_H
