//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_ASTR_H
#define SISE_ASTR_H

#include "strategy/strategy.h"
#include "hamming.h"
#include "manhattan.h"

namespace sise {

    class ASTR : public strategy {
    public:
        explicit ASTR(const std::string &arg);

        bool solve(std::shared_ptr<board> board) override;

    private:
        std::shared_ptr<heuristics> heuristic;
    };

}

#endif //SISE_ASTR_H
