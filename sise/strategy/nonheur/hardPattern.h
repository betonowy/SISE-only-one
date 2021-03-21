//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_HARDPATTERN_H
#define SISE_HARDPATTERN_H

#include <string>
#include <board/board.h>
#include <array>

namespace sise {

    class hardPattern {
    public:
        explicit hardPattern(const std::string &arg);

        inline const auto &operator()() const { return pattern; }

    private:
        std::array<moveDirection, 4> pattern{};
    };

}

#endif //SISE_HARDPATTERN_H
