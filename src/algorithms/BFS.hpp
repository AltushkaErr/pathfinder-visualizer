#include <vector>
#include "core/point.hpp"
#include "core/grid.hpp"

struct SearchResult {
    std::vector<Point> path;
    int visitedNodes {0};
    double elapsedMs {0.0}; // для сравнения
};

class BFS {
public:
    SearchResult run(const Grid& grid);
};
