cmake_minimum_required(VERSION 3.26)

project(programy_c___tep)

set(CMAKE_CXX_STANDARD 17)


add_executable(programy_c___tep main.cpp
        src/Zad1/CTable.hpp
        src/Tool.hpp
        src/Zad1/Functions.h
        src/Zad2/CNumber.cpp
        src/Zad2/CNumber.h
        src/Zad2/ConstansZad2.h
        src/Zad3/CNode.cpp
        src/Zad3/CNode.h
        src/Zad3/CTree.cpp
        src/Zad3/CTree.h
        src/Zad3/Operators.cpp
        src/Zad3/Operators.h
        src/Zad3/ConstansZad3.h
        src/Zad3/CLIZad3.cpp
        src/Zad3/CLIZad3.h
        src/Zad4/Functions.cpp
        src/Zad4/Functions.h
        src/Zad4/CResult.cpp
        src/Zad4/CResult.h
        src/Zad4/CError.cpp
        src/Zad4/CError.h
        src/Zad4/ConstansZad4.h
        src/Zad5/CMySmartPointer.cpp
        src/Zad5/CMySmartPointer.h
        src/Zad5/CRefCounter.cpp
        src/Zad5/CRefCounter.h
        src/miniProjekt/DistanceFunction.h
        src/miniProjekt/AG_0.cpp
        src/miniProjekt/AG_0.h
)


include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)


add_executable(test_zad3
        tests/test.cpp
        src/Zad1/CTable.hpp
        src/Tool.hpp
        src/Zad1/Functions.h
        src/Zad2/CNumber.cpp
        src/Zad2/CNumber.h
        src/Zad2/ConstansZad2.h
        src/Zad3/CNode.cpp
        src/Zad3/CNode.h
        src/Zad3/CTree.cpp
        src/Zad3/CTree.h
        src/Zad3/Operators.cpp
        src/Zad3/Operators.h
        src/Zad3/ConstansZad3.h
        src/Zad3/CLIZad3.cpp
        src/Zad3/CLIZad3.h
        src/Zad4/Functions.cpp
        src/Zad4/Functions.h
        src/Zad4/CResult.cpp
        src/Zad4/CResult.h
        src/Zad4/CError.cpp
        src/Zad4/CError.h
        src/Zad4/ConstansZad4.h
)


target_link_libraries(test_zad3 gtest_main)

add_test(NAME TestZad3 COMMAND test_zad3)






