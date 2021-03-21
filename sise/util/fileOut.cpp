//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "fileOut.h"

namespace sise {

    fileOut::fileOut(const std::string &path) : file(path) {}

    void fileOut::outString(const std::string &input) { file << input << " "; }

    void fileOut::outFloat(double input) { file << input << " "; }

    void fileOut::outInt(int input) { file << input << " "; }

    void fileOut::newLine() { file << "\n"; }

}
