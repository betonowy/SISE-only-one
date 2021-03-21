//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "fileIn.h"

namespace sise {

    fileIn::fileIn(const std::string &path) : file(path, std::ios::in) {}

    std::string fileIn::getString() {
        std::string input;
        file >> input;
        return input;
    }

    float fileIn::getFloat() {
        float input;
        file >> input;
        return input;
    }

    int fileIn::getInt() {
        int input;
        file >> input;
        return input;
    }

    bool fileIn::eof() {
        return file.eof();
    }

}