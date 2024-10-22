cmake_minimum_required(VERSION 3.27)
project(programy_c___tep)

set(CMAKE_CXX_STANDARD 17)

add_executable(programy_c___tep main.cpp
        src/Zad1/CTable.hpp
        src/Tool.hpp
        src/Zad1/Functions.h
        src/Zad2/CNumber.cpp
        src/Zad2/CNumber.h
        src/Zad2/Constans.h)
