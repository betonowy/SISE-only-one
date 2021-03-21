//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "timer.h"

namespace sise {

    void timer::start() {
        startPoint = clockType::now();
    }

    double timer::get() {
        timePoint now = clockType::now();
        return std::chrono::duration_cast<timeBase>(now - startPoint).count() * 0.001f;
    }

}
