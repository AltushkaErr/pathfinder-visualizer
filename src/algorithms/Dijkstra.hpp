#pragma once
#include "core/grid.hpp"
#include "core/searchResult.hpp"

struct CompareNode {
    bool operator()(const std::pair<int, Point>&a,
                    const std::pair<int, Point>& b) const {
        return a.first > b.first;
    }
};

class Dijkstra {
public:
    SearchResult run(const Grid& grid);
};