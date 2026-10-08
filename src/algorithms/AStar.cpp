#include "AStar.hpp"

#include <queue>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include <cstdlib>

namespace {
    int heuristic(Point a, Point b){
        return std::abs(a.x - b.x) + std::abs(a.y - b.y);
    }
}

struct CompareNode {
    bool operator()(const std::pair<int, Point>&a,
                    const std::pair<int, Point>& b) const {
        return a.first > b.first;
    }
};

SearchResult AStar::run(const Grid& grid){
    SearchResult result;

    const Point start = grid.start();
    const Point goal = grid.goal();

    using Node = std::pair<int, Point>;
    std::priority_queue<Node, std::vector<Node>, CompareNode> frontier;
    std::unordered_map<Point, int> dist;
    std::unordered_map<Point, Point> parent;
    std::unordered_map<Point, bool> visited;

    auto startTime = std::chrono::high_resolution_clock::now();

    dist[start] = 0;
    frontier.push({heuristic(start, goal), start});
    const Point dirs[4] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    bool found = false;

    while (!frontier.empty()){
        auto [priority, cur] = frontier.top();
        frontier.pop();

        if (visited[cur]) continue;
        visited[cur] = true;
        result.visitedNodes++;
        result.visitOrder.push_back(cur);

        if (cur == goal){
            found = true;
            break;
        }

        int cost = dist[cur];
        for (const Point& d : dirs){
            Point next {cur.x + d.x, cur.y + d.y};
            if (!grid.isWalkable(next)) continue;

            int newCost = cost + 1;
            auto it = dist.find(next);
            if (it == dist.end() || newCost < it->second){
                dist[next] = newCost;
                parent[next] = cur;
                int priority = newCost  + heuristic(next, goal);

                frontier.push({priority, next});
            }
        }
    }

    if (found) {
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