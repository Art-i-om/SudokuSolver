#pragma once
#include <vector>
#include <set>
#include "GridPosition.hpp"

class Cell {
private:
    GridPosition grid_position;
    std::vector<int> valid_values;
    int value = 0;

public:
    GridPosition getGridPosition() { return grid_position; }
    int getValue() { return value; }
    std::vector<int> getValidValues() { return valid_values; }
    void setValue(const int& val) { value = val; valid_values.clear(); }
    void setGridPosition(const GridPosition& grPos) { grid_position = grPos; }
    void setValidValues(const std::vector<int>& valid) { valid_values = valid; }
    bool isEmpty() { return getValue() == 0; }
};
