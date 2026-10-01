#pragma once
#include <vector>
#include "point.hpp"

struct SearchResult {
    std::vector<Point> path;
    int visitedNodes {0};
    double elapsedMs {0.0};
};
