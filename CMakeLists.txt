cmake_minimum_required(VERSION 3.31)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(SudokuSolver main.cpp
        src/files/FileHelper.cpp
        src/files/FileHelper.hpp
        src/gridUtils/GridPosition.cpp
        src/gridUtils/GridPosition.hpp
        src/gridUtils/Cell.cpp
        src/gridUtils/Cell.hpp
        src/boardUtils/SudokuSolver.cpp
        src/boardUtils/SudokuSolver.hpp
)
