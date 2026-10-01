#include "grid.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

Grid Grid::fromFile(const std::string& path) {
    Grid g;
    std::ifstream in(path);
    if (!in) {
        throw std::runtime_error("Can't open file: " + path);
    }

    std::string line;
    while (std::getline(in, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        g.cells_.push_back(line);
    }
    //std::cout << "Read complete. Close file\n.";

    if (g.cells_.empty()) {
        // std::cout << "Empty data. Emergency close.\n";
        // return;
        throw std::runtime_error("File empty: " + path);
    }

    g.height_ = static_cast<int>(g.cells_.size());
    g.width_  = static_cast<int>(g.cells_[0].size());

    for (int y = 0; y < g.height_; ++y) {
        for (int x = 0; x < g.width_; ++x) {
            char ch = g.cells_[y][x];
            if (ch == 'S') g.start_ = {x, y};
            if (ch == 'E') g.goal_  = {x, y};
        }
    }

    return g;
}

bool Grid::inBounds(Point p) const {
    return p.x >= 0 && p.y >= 0 && p.x < width_ && p.y < height_;
}

bool Grid::isWalkable(Point p) const {
    if (!inBounds(p)) return false;
    return cells_[p.y][p.x] != '#';
}

char Grid::at(Point p) const {
    return inBounds(p) ? cells_[p.y][p.x] : '#';
}

void Grid::print(const std::vector<Point>& path) const {
    // for (const auto& row : cells_) {
    //     std::cout << row << '\n';
    // }
    std::vector<std::string> copy = cells_;
    for (const Point& p : path){
        if (inBounds(p) && copy[p.y][p.x] == '.'){
            copy[p.y][p.x] = '*';
        }
    }
    for (const auto& row : copy){
        std::cout << row << '\n';
    }
}