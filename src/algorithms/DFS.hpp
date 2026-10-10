#pragma once

#include "Algorithm.hpp"


class DFS : public Algorithm{
public:
    SearchResult run(const Grid& grid) override;
    const char* name() const override { return "DFS"; }
};