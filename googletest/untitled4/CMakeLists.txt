cmake_minimum_required(VERSION 3.20)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
set(SOURCE_FILES main.cpp)
add_executable(untitled4 test.cpp test.h main.cpp)
target_link_libraries(untitled4 gtest gtest_main)