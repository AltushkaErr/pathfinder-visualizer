#include "DFS.hpp"
#include <unordered_map>
#include <stack>
#include <chrono>
#include <algorithm>

SearchResult DFS::run(const Grid& grid){
    SearchResult result;

    std::stack<Point> frontierChain;
    std::unordered_map<Point, Point> parent;
    std::vector<bool> visited(grid.width() * grid.height(), false);
    auto startTime = std::chrono::high_resolution_clock::now();

    const Point start = grid.start();
    const Point goal = grid.goal();
    const Point dirs[4] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    bool found = false;

    frontierChain.push(start);
    visited[start.y * grid.width() + start.x] = true;

    while (!frontierChain.empty()){
        Point cur = frontierChain.top();
        frontierChain.pop();
        result.visitedNodes++;
        if (cur == goal){
            found = true;
            break;
        }
        visited[start.y * grid.width() + start.x] = true;
        for (const Point& d : dirs){
            Point next{cur.x + d.x, cur.y + d.y};
            if (!grid.isWalkable(next)) continue;
            if (visited[next.y * grid.width() + next.x]) continue;
            // parent[next] = cur;
            // frontierChain.push(next);

            visited[next.y * grid.width() + next.x] = true;
            parent[next] = cur;
            frontierChain.push(next);
        }
        
    }

    if (found){
    Point cur = goal;
    while (!(cur == start)){
        result.path.push_back(cur);
        cur = parent[cur];
    }
    result.path.push_back(start);
    std::reverse(result.path.begin(), result.path.end());
    }
    
    auto stopTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = stopTime - startTime;
    result.elapsedMs = elapsed.count();
    return result;
}
