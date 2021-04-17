cmake_minimum_required(VERSION 3.17)
project(SISE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-g -pipe -Wall -Wextra -Wpedantic -DSISE_FAILSAFE")
set(CMAKE_CXX_FLAGS_RELEASE "-s -O3 -pipe -Wall -Wextra -Wpedantic -fno-exceptions -DNO_EXCEPTIONS")

file(GLOB_RECURSE SRCS sise/*.cpp)
file(GLOB_RECURSE HDRS sise/*.h)

add_executable(SISE main.cpp ${SRCS} ${HDRS})
target_include_directories(SISE PUBLIC BEFORE sise)

target_link_libraries(SISE tbb)
