//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "siseException.h"

#ifdef NO_EXCEPTIONS
#include <iostream>
#endif

namespace sise {

    void Throw(const std::string &reason) {
#ifdef NO_EXCEPTIONS
        std::cout << reason << std::endl;
        std::abort();
#else
        throw exception(reason);
#endif
    }

    exception::exception(const std::string &reason) : exceptionString("SISE: " + reason) {}

    const char *exception::what() const noexcept { return exceptionString.c_str(); }

}