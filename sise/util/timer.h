//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_TIMER_H
#define SISE_TIMER_H

#include <chrono>

namespace sise {

    class timer {
        using clockType = std::chrono::steady_clock;
        using timePoint = std::chrono::time_point<clockType>;
        using timeBase = std::chrono::microseconds;

    public:
        void start();

        double get();

    private:
        timePoint startPoint;
    };

}

#endif //SISE_TIMER_H
