#include <iostream>
#include "core/grid.hpp"
#include "algorithms/BFS.hpp"
#include "algorithms/DFS.hpp"
#include "algorithms/Dijkstra.hpp"

int main(int argc, char** argv){
    if (argc < 2){
        std::cerr << "Using: " << argv[0] << " <maze.txt>\n";
        return 1;
    }
    // try {
    //     Grid grid = Grid::fromFile(argv[1]);
    //     std::cout << "Size: " << grid.width() << "x" << grid.height() << '\n';
    //     std::cout << "Start: " << grid.start().x << ", " << grid.start().y << '\n';
    //     std::cout << "Target: " << grid.goal().x << ", " << grid.goal().y << '\n';

    //     grid.print();
    // } catch (const std::exception& e){
    //     std::cerr << "Error: " << e.what() << '\n';
    //     return 1;
    // }

    Grid grid = Grid::fromFile(argv[1]);
    grid.print();
    std::cout << "\n=== BFS ===\n";
    BFS bfs;
    SearchResult result = bfs.run(grid);
    std::cout << "Visited: " << result.visitedNodes << '\n';
    std::cout << "Path length: " << result.path.size() << '\n';
    std::cout << "Time: " << result.elapsedMs << " ms.\n";
    grid.print(result.path);
    std::cout << "\n=== DFS ===\n";
    DFS dfs;
    SearchResult result2 = dfs.run(grid);
    std::cout << "Visited: " << result2.visitedNodes << '\n';
    std::cout << "Path length: " << result2.path.size() << '\n';
    std::cout << "Time: " << result2.elapsedMs << " ms.\n";
    grid.print(result2.path);
    std::cout << "\n=== Dijkstra ===\n";
    Dijkstra dij;
    SearchResult result3 = dij.run(grid);
    std::cout << "Visited: " << result3.visitedNodes << '\n';
    std::cout << "Path length: " << result3.path.size() << '\n';
    std::cout << "Time: " << result3.elapsedMs << " ms.\n";
    grid.print(result3.path);
    return 0;
}
