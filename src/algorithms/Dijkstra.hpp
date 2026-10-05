#pragma once
#include "core/grid.hpp"
#include "core/searchResult.hpp"


class Dijkstra {
public:
    SearchResult run(const Grid& grid);
};