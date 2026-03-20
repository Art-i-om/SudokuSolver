#include <vector>
#include <iostream>
#include <algorithm>
#include "src/boardUtils/SudokuSolver.hpp"
#include "src/files/FileHelper.hpp"
#include "src/gridUtils/Cell.hpp"
#include "src/gridUtils/GridPosition.hpp"

int main() {
    std::vector<std::string> board = getWordsFromFile("../board.txt");

    size_t board_length = 9;
    size_t board_size = board_length * board_length;

    std::vector<Cell> cells(board_size);
    for (size_t idx = 0; idx < board_size; idx++) {
        GridPosition gridPos = get2DCoords(idx, board_length);

        cells[idx].setGridPosition(gridPos);
        cells[idx].setValue(board[idx][0] - '0');
    }

    for (size_t idx = 0; idx < board_size; idx++) {
        std::vector<int> valid = getValidValues(cells, cells[idx].getGridPosition());
        cells[idx].setValidValues(valid);
    }

    for (size_t idx = 0; idx < board_size; idx++) {
        auto cell = &cells[idx];
        if (cell->getValidValues().size() == 1) {
            auto validValue = cell->getValidValues()[0];
            cell->setValue(validValue);
        }
    }

    if (solveBoard(cells)) {
        std::cout << "Board Solved!\n";
    }
    else {
        std::cout << "Board not solved...\n";
    }

    for (int i = 0; i < board_length; i++) {
        for (int j = 0; j < board_length; j++) {
            std::cout << cells[i * board_length + j].getValue() << " ";
        }

        std::cout << "\n";
    }
}