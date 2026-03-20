#pragma once
#include <iostream>

struct GridPosition {
    size_t row;
    size_t column;
    size_t box;
    size_t index;

    GridPosition() : row(-1), column(-1), box(-1), index(-1) {}
};

GridPosition get2DCoords(size_t& index, size_t& n);
