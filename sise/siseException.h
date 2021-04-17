//
// Created by Mikołaj Bajkowski (ara ara this yo mama) on 21.03.2021.
//

#ifndef SISE_SISEEXCEPTION_H
#define SISE_SISEEXCEPTION_H

#include <exception>
#include <string>

namespace sise {

    void Throw(const std::string &reason);

    class exception : public std::exception {
    public:
        explicit exception(const std::string& reason);

        [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

    private:
        std::string exceptionString;
    };

}


#endif //SISE_SISEEXCEPTION_H
