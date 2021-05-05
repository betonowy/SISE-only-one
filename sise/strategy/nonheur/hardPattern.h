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

        inline const auto &operator[](size_t index) const { return pattern[index]; }

        inline constexpr size_t size() { return pattern.size(); }

        inline const auto &operator()() const { return pattern; }

        [[nodiscard]] inline const auto &Reversed() const { return reversePattern; }

    private:
        std::array<moveDirection, 4> pattern{};
        std::array<moveDirection, 4> reversePattern{};
    };

}

#endif //SISE_HARDPATTERN_H
