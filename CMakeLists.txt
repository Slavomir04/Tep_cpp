cmake_minimum_required(VERSION 3.27)
project(programy_c___tep)

set(CMAKE_CXX_STANDARD 17)

add_executable(programy_c___tep main.cpp
        Person.hpp
        src/CTable.hpp
        src/Tool.hpp)
