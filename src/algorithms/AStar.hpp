#pragma once

#include "core/grid.hpp"
#include "core/point.hpp"
#include "core/searchResult.hpp"

class AStar {
public:
    SearchResult run(const Grid& grid);
};


