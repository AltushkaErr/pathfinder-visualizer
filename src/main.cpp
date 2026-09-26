#include <iostream>
#include "core/grid.hpp"

int main(int argc, char** argv){
    if (argc < 2){
        std::cerr << "Using: " << argv[0] << " <maze.txt>\n";
        return 1;
    }
    try {
        Grid grid = Grid::fromFile(argv[1]);
        std::cout << "Size: " << grid.width() << "x" << grid.height() << '\n';
        std::cout << "Start: " << grid.start().x << ", " << grid.start().y << '\n';
        std::cout << "Target: " << grid.goal().x << ", " << grid.goal().y << '\n';

        grid.print();
    } catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
