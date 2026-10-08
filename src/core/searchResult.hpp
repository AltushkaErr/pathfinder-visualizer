#pragma once
#include <vector>
#include "point.hpp"

struct SearchResult {
    std::vector<Point> path;
    std::vector<Point> visitOrder; // for animation
    int visitedNodes {0};
    double elapsedMs {0.0};
};
