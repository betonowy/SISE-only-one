//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "arguments.h"

sise::arguments::arguments(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        args.emplace_back(argv[i]);
    }
}

size_t sise::arguments::size() { return args.size(); }

std::string &sise::arguments::operator[](size_t index) { return args[index]; }
