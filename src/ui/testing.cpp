
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