#include "GridPosition.hpp"

GridPosition get2DCoords(size_t& index, size_t &n) {
    GridPosition pos;

    pos.index = index;
    pos.row = index / n;
    pos.column = index % n;
    pos.box = (pos.row / (n / 3)) * 3 + (pos.column / (n / 3));

    return pos;
}
