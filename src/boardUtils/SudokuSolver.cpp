#include "SudokuSolver.hpp"

std::vector<int> getValidValues(std::vector<Cell> &cells, const GridPosition& position) {
    if (cells[position.index].getValue() != 0) return {};

    bool used[10] = {false};

    size_t row = position.row;
    size_t column = position.column;

    for (int c = 0; c < 9; c++) {
        used[cells[row * 9 + c].getValue()] = true;
    }

    for (int r = 0; r < 9; r++) {
        used[cells[r * 9 + column].getValue()] = true;
    }

    size_t br = (row / 3) * 3;
    size_t bc = (column / 3) * 3;

    for (int r = br; r < br + 3; r++) {
        for (int c = bc; c < bc + 3; c++) {
            used[cells[r*9 + c].getValue()] = true;
        }
    }

    std::vector<int> result;

    for (int n = 1; n <= 9; n++) {
        if (!used[n]) {
            result.push_back(n);
        }
    }

    return result;
}

void updateAllValidValues(std::vector<Cell> &cells) {
    for (auto& cell : cells) {
        if (cell.isEmpty()) {
            auto validValues = getValidValues(cells, cell.getGridPosition());
            cell.setValidValues(validValues);
        }
    }
}


bool solveBoard(std::vector<Cell> &cells) {
    updateAllValidValues(cells);

    bool allCellsFilled = true;
    for (auto& cell : cells) {
        if (cell.isEmpty()) {
            allCellsFilled = false;
            if (cell.getValidValues().empty()) {
                return false;
            }
        }
    }

    if (allCellsFilled) {
        return true;
    }

    std::vector<Cell*> emptyCells;

    for (auto& cell : cells) {
        if (cell.isEmpty()) {
            emptyCells.push_back(&cell);
        }
    }

    auto current = emptyCells[0];

    for (auto value : current->getValidValues()) {
        current->setValue(value);

        if (solveBoard(cells)) {
            return true;
        }

        current->setValue(0);
    }

    return false;
}
