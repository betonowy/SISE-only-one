//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_ARGUMENTS_H
#define SISE_ARGUMENTS_H

#include <string>
#include <deque>

namespace sise {

    class arguments {
    public:
        arguments(int argc, char **argv);

        size_t size();

        std::string &operator[](size_t index);

    private:
        std::deque<std::string> args;
    };

}

#endif //SISE_ARGUMENTS_H
