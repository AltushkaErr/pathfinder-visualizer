#pragma once

#include "core/grid.hpp"
#include "core/point.hpp"
#include "core/searchResult.hpp"

class Algorithm {
public:
    virtual ~Algorithm() = default;
    virtual SearchResult run(const Grid& grid) = 0;
    virtual const char* name() const = 0;
};