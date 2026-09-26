#pragma once

#include <vector>
#include <string>
#include "point.hpp"


class Grid{
private:
    std::vector<std::string> cells_;
    int width_ {0};
    int height_ {0};
    Point start_ {};
    Point goal_ {};
public:
    static Grid fromFile(const std::string& path);

    int width() const {return width_;}
    int height() const {return height_;}
    Point start() const{return start_;}
    Point goal() const {return goal_;}

    bool inBounds(Point p) const;
    bool isWalkable(Point p) const ;
    char at(Point p) const ;
    void print() const;
};
