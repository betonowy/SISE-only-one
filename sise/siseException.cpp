//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#include "siseException.h"

namespace sise {

    exception::exception(const std::string &reason) : exceptionString("SISE: " + reason) {}

    const char *exception::what() const noexcept { return exceptionString.c_str(); }

}