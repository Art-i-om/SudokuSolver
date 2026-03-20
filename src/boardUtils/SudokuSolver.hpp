#pragma once
#include <vector>
#include "../gridUtils/Cell.hpp"

std::vector<int> getValidValues(std::vector<Cell>& cells, const GridPosition& position);
void updateAllValidValues(std::vector<Cell>& cells);

bool solveBoard(std::vector<Cell>& cells);