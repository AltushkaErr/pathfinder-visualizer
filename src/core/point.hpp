/// Структура хранения клеток
#pragma once
#include <cstddef>
#include <functional>

struct Point {
    int x;
    int y;

    // Переопрделение оператора для сравнения любых точек
    // 
    bool operator== (const Point& o) const 
    {return x == o.x && y == o.y;}
};

// расчет хэша для ключа
template<>
struct std::hash<Point>{
    size_t operator()(const Point& p) const noexcept {
        return std::hash<int>{}(p.x) ^ (std::hash<int>{}(p.x) << 1);
    }
};