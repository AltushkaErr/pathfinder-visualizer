/// Структура хранения клеток
#pragma once
#include <cstddef>
#include <functional>

struct Point {
    int x;
    int y;

    bool operator== (const Point& o) const 
    {return x == o.x && y == o.y;}
};

template<>
struct std::hash<Point>{
    size_t operator()(const Point& p) const noexcept {
        return std::hash<int>{}(p.x) ^ (std::hash<int>{}(p.x) << 1);
    }
};