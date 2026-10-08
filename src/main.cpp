#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>
#include <chrono>
#include <sstream>

#include "core/grid.hpp"
#include "algorithms/Algorithm.hpp"
#include "algorithms/BFS.hpp"
#include "algorithms/DFS.hpp"
#include "algorithms/Dijkstra.hpp"
#include "algorithms/AStar.hpp"

#include <SFML/Graphics.hpp>

int main(/*int argc, char** argv*/){
    // if (argc < 2){
    //     std::cerr << "Using: " << argv[0] << " <maze.txt>\n";
    //     return 1;
    // }

    /// Testing all algorithms 

    // Grid grid = Grid::fromFile(argv[1]);
    // grid.print();
    // std::cout << "\n=== BFS ===\n";
    // BFS bfs;
    // SearchResult result = bfs.run(grid);
    // std::cout << "Visited: " << result.visitedNodes << '\n';
    // std::cout << "Path length: " << result.path.size() << '\n';
    // std::cout << "Time: " << result.elapsedMs << " ms.\n";
    // grid.print(result.path);

    // std::cout << "\n=== DFS ===\n";
    // DFS dfs;
    // SearchResult result2 = dfs.run(grid);
    // std::cout << "Visited: " << result2.visitedNodes << '\n';
    // std::cout << "Path length: " << result2.path.size() << '\n';
    // std::cout << "Time: " << result2.elapsedMs << " ms.\n";
    // grid.print(result2.path);

    // std::cout << "\n=== Dijkstra ===\n";
    // Dijkstra dij;
    // SearchResult result3 = dij.run(grid);
    // std::cout << "Visited: " << result3.visitedNodes << '\n';
    // std::cout << "Path length: " << result3.path.size() << '\n';
    // std::cout << "Time: " << result3.elapsedMs << " ms.\n";
    // grid.print(result3.path);

    // std::cout << "\n=== A* ===\n";
    // AStar astar;
    // SearchResult result4 = astar.run(grid);
    // std::cout << "Visited: " << result4.visitedNodes << '\n';
    // std::cout << "Path length: " << result4.path.size() << '\n';
    // std::cout << "Time: " << result4.elapsedMs << " ms.\n";
    // grid.print(result4.path);


    /// Comprasion Table 

    // Grid grid = Grid::fromFile(argv[1]);
    // std::vector<std::unique_ptr<Algorithm>> algorithms;
    // algorithms.push_back(std::make_unique<BFS>());
    // algorithms.push_back(std::make_unique<DFS>());
    // algorithms.push_back(std::make_unique<Dijkstra>());
    // algorithms.push_back(std::make_unique<AStar>());
    

    // std::cout << "Filemap: " << argv[1] << '\n';
    // std::cout << std::left
    //           << std::setw(12) << "Algorithm"
    //           << std::setw(10) << "Visited"
    //           << std::setw(14) << "Path Length"
    //           << std::setw(12) << "Time (ms)"
    //           << '\n';
    // std::cout << std::string(48, '-') << '\n';

    // for (const auto& algo : algorithms){
    //     SearchResult r = algo->run(grid);
    //     std::cout << std::left
    //               << std::setw(12) << algo->name()
    //               << std::setw(10) << r.visitedNodes
    //               << std::setw(14) << r.path.size()
    //               << std::setw(12) << std::fixed << std::setprecision(3)
    //               << r.elapsedMs
    //               << '\n';
    // }

    /// Testing draw the cell

    // Grid grid = Grid::fromFile("assets/mazes/small.txt");
    // const int CELL_SIZE = 60;
    // sf::RenderWindow window(
    //     sf::VideoMode(grid.width() * CELL_SIZE, grid.height() * CELL_SIZE),
    //     "Pathfinder"
    // );
    // while (window.isOpen()){
    //     sf::Event event;
    //     while (window.pollEvent(event)){
    //         if (event.type == sf::Event::Closed){
    //             window.close();
    //         }
    //     }
    //     window.clear(sf::Color::Black);

    //     sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    //     for (int y = 0; y < grid.height(); ++y){
    //         for (int x = 0; x < grid.width(); ++x){
    //             Point p {x, y};
    //             char ch = grid.at(p);

    //             sf::Color color;
    //             if (ch == '#') color = sf::Color(40, 40, 40);
    //             else if (ch == 'S') color = sf::Color::Green;
    //             else if (ch == 'E') color = sf::Color::Red;
    //             else color = sf::Color(220, 220, 220);

    //             cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
    //             cell.setFillColor(color);
    //             window.draw(cell);
    //         }
    //     }

    //     window.display();
    // }

    Grid grid = Grid::fromFile("assets/mazes/small.txt");
    std::vector<std::unique_ptr<Algorithm>> algorithms;
    algorithms.push_back(std::make_unique<BFS>());
    algorithms.push_back(std::make_unique<DFS>());
    algorithms.push_back(std::make_unique<Dijkstra>());
    algorithms.push_back(std::make_unique<AStar>());

    int currentAlgo = 0;
    SearchResult result = algorithms[currentAlgo]->run(grid);

    const int CELL_SIZE = 90;
    sf::RenderWindow window(
        sf::VideoMode(grid.width() * CELL_SIZE, grid.height() * CELL_SIZE),
        "Pathfinder"
    );

    // Counters for grid cell
    size_t visitStep = 0;
    size_t pathStep = 0;
    auto lastUpdate = std::chrono::steady_clock::now();
    // step animation
    const int STEP_MS = 30;

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")){
        std::cerr << "Can't load fonts style\n";
        return 1;
    }

    
    sf::Text metricsText;
    metricsText.setFont(font);
    metricsText.setCharacterSize(16);
    metricsText.setFillColor(sf::Color::White);
    
    /// Events processing 
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed){
                int newAlgo = -1;
                if (event.key.code == sf::Keyboard::Num1) newAlgo = 0;
                if (event.key.code == sf::Keyboard::Num2) newAlgo = 1;
                if (event.key.code == sf::Keyboard::Num3) newAlgo = 2;
                if (event.key.code == sf::Keyboard::Num4) newAlgo = 3;

                if (newAlgo >= 0 && newAlgo != currentAlgo){
                    currentAlgo = newAlgo;
                    window.setTitle("Pathfindet - " + std::string(algorithms[currentAlgo]->name()));
                    result = algorithms[currentAlgo]->run(grid);
                    visitStep = 0;
                    pathStep = 0;
                    lastUpdate = std::chrono::steady_clock::now();
                }

                if (event.key.code == sf::Keyboard::R){
                    visitStep = 0;
                    pathStep = 0;
                    lastUpdate = std::chrono::steady_clock::now();
                }
            }
        }

        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastUpdate).count();
        if (elapsed >= STEP_MS){
            lastUpdate = now;
            if (visitStep < result.visitOrder.size()){
                visitStep++;
            } else if (pathStep < result.path.size()){
                pathStep++;
            }
        }

        window.clear(sf::Color::Black);
        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        for (int y = 0; y < grid.height(); ++y){
            for (int x = 0; x < grid.width(); ++x){
                Point p { x, y};
                char ch = grid.at(p);

                sf::Color color;
                if (ch == '#')      color = sf::Color(40, 40, 40);
                else if (ch == 'S') color = sf::Color::Green;
                else if (ch == 'E') color = sf::Color::Red;
                else                color = sf::Color(220, 220, 220);

                cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                cell.setFillColor(color);
                window.draw(cell);
            }
            sf::RectangleShape visitedCell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            visitedCell.setFillColor(sf::Color(155, 191, 244));
            for (size_t i = 0; i < visitStep &&
                               i < result.visitOrder.size(); ++i){
                Point p = result.visitOrder[i];
                visitedCell.setPosition(p.x * CELL_SIZE, p.y* CELL_SIZE);
                window.draw(visitedCell);
            }

            sf::RectangleShape pathCell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            pathCell.setFillColor(sf::Color(74, 128, 245));
            for (size_t i = 0; i < pathStep && i < result.path.size(); ++i){
                Point p = result.path[i];
                pathCell.setPosition(p.x * CELL_SIZE, p.y * CELL_SIZE);
                window.draw(pathCell);
            }
        }   
        
        /// Metrics algorithms

        sf::RectangleShape metricsBg(sf::Vector2f(220, 110));
        metricsBg.setFillColor(sf::Color(0,0,0,180));
        metricsBg.setPosition(10, 10);
        window.draw(metricsBg);

        std::ostringstream oss;
        oss << algorithms[currentAlgo]->name() << "\n"
            << "Visited: " << result.visitedNodes << "\n"
            << "Path Length: " << result.path.size() << "\n"
            << "Time: " << result.elapsedMs << " ms";
        
        metricsText.setString(oss.str());
        metricsText.setPosition(20, 20);
        window.draw(metricsText);

        window.display();
    }

    return 0;
}
