//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_FILEIN_H
#define SISE_FILEIN_H

#include <fstream>

namespace sise {

    class fileIn {
    public:
        explicit fileIn(const std::string &path);

        std::string getString();

        float getFloat();

        int getInt();

        bool eof();

    private:
        std::ifstream file;
    };

}

#endif //SISE_FILEIN_H
