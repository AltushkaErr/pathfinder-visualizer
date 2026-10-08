#include "BFS.hpp"
#include <unordered_map>
#include <chrono>
#include <queue>
#include <algorithm>

SearchResult BFS::run(const Grid& grid){
    SearchResult result;

    std::queue<Point> frontier;
    std::unordered_map<Point, Point> parent;
    std::vector<bool> visited(grid.width() * grid.height(), false);
    auto startTime = std::chrono::high_resolution_clock::now();

    const Point start = grid.start();
    const Point goal = grid.goal();
    const Point dirs[4] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    bool found = false;

    frontier.push(start);
    visited[start.y * grid.width() + start.x * grid.height()] = true;

    while (!frontier.empty()){
        Point cur = frontier.front();
        frontier.pop();
        result.visitedNodes++;
        result.visitOrder.push_back(cur);
        
        //if (!visited[cur.y * grid.width() + cur.x]){
        if (cur == goal){
            // обновление количества пройденых точек
            // окончание времени
            // запись пути
            found = true;
            break;
        }
        
            // добавление в очередь дочерних узлов
        for (const Point& d : dirs){
            Point next{cur.x + d.x, cur.y + d.y};
            if (!grid.isWalkable(next)) continue;                
            if (visited[next.y * grid.width() + next.x]) continue;
            visited[next.y * grid.width() + next.x] = true;
            parent[next] = cur;
            frontier.push(next);
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