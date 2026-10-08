#pragma once

#include "Algorithm.hpp"

// struct SearchResult {
//     std::vector<Point> path;
//     int visitedNodes {0};
//     double elapsedMs {0.0}; // для сравнения
// };

class BFS : public Algorithm{
public:
    SearchResult run(const Grid& grid) override;
    const char* name() const override { return "BFS"; }
};
