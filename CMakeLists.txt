cmake_minimum_required(VERSION 3.20)
project(pathfinder CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

add_executable(pathfinder
    src/main.cpp
    src/core/grid.cpp
    src/algorithms/BFS.cpp
    src/algorithms/DFS.cpp
    src/algorithms/Dijkstra.cpp
    src/algorithms/AStar.cpp
)

target_include_directories(pathfinder PRIVATE src)

target_link_libraries(pathfinder PRIVATE sfml-graphics sfml-window sfml-system)