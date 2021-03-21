//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_FILEOUT_H
#define SISE_FILEOUT_H

#include <fstream>

namespace sise {

    class fileOut {
    public:
        explicit fileOut(const std::string &path);

        void outString(const std::string &input);

        void outFloat(double input);

        void outInt(int input);

        void newLine();

    private:
        std::ofstream file;
    };

}

#endif //SISE_FILEOUT_H
