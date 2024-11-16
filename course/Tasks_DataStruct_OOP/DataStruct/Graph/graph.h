//
//  iTest.h
//  Test2019
//
//  Created by Denys Risukhin on 7/9/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef iTest_h
#define iTest_h

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <iomanip>
#include <array>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstdlib>

//include <unordered_map>


template<class L>
class Graph {
public:
    //typedef L Location;
    //typedef typename std::vector<Location>::iterator iterator;
    using Location = L;
    using iterator = typename std::vector<Location>::iterator;
    
    std::vector<Location> neighbors(Location id) {
        return edges[id];
    }
    
//private:
     std::unordered_map<Location, std::vector<Location>> edges;
};

#pragma mark - breadthFirstSearch

//template<class G>
//void breadthFirstSearch(G graph, typename G::Location start) {
//    //typedef typename G::Location Location;
//    using Location = typename G::Location;
//
//    std::queue<Location> frontier;
//    frontier.push(start);
//
//    std::unordered_set<Location> visited;
//    visited.insert(start);
//
//    while (!frontier.empty()) {
//        auto current = frontier.front();
//        frontier.pop();
//        std::cout << "visiting" << current << std::endl;
//
//        for (auto & next: graph.neighbors(current)) {
//            // !visited.count(next)
//            // исчем контейнер для эл-ов со значениями next
//            // возвр 1 если элемент с этим знач существует
//            // 0 - не сущ.
//            if (!visited.count(next)) {
//                frontier.push(next);
//                visited.insert(next);
//            }
//        }
//
//    }
//}



#pragma mark - priority_queue

template<typename T, typename priority_t>
struct priority_queue
{
    typedef std::pair<priority_t, T> PQElement;
    std::priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement>> elements;
    
    bool empty() const { return elements.empty(); }
    
    void put(T item, priority_t priority) { elements.emplace(priority, item); }
    
    T get()
    {
        T best_item = elements.top().second;
        elements.pop();
        return best_item;
    }
};

#pragma mark - dijkstra_search

template<typename G>
void dijkstra_search(const G& graph,
                     typename G::Location start,
                     typename G::Location goal,
                     std::unordered_map<typename G::Location, typename G::Location>& came_from,
                     std::unordered_map<typename G::Location, double>& cost_so_far)
{
   // typedef typename G::Location Location;
    using Location = typename G::Location;
    
    priority_queue<Location, double> frontier;
    frontier.put(start, 0);
    
    came_from[start] = start;
    cost_so_far[start] = 0;
    
    while (!frontier.empty()) {
        auto current = frontier.get();
        
        if (current == goal) {
            break;
        }
        
        for (auto& next: graph.neightbors(current))
        {
            double newCost = cost_so_far[current] + graph.cost(current, next);

            if (!cost_so_far.count(next) || newCost < cost_so_far[next])
            {
                cost_so_far[next] = newCost;
                came_from[next] = current;
                frontier.put(next, newCost);
            }
        }
    }
}

#pragma mark - reconstruct_path

template<typename Location>
std::vector<Location> reconstruct_path(Location start, Location goal, std::unordered_map<Location, Location>& came_from)
{
    std::vector<Location> path;
    Location current = goal;
    path.push_back(current);
    while(current != start)
    {
        current = came_from[current];
        path.push_back(current);
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}

#pragma mark - square_grid

struct GridLocation {
    int x, y;
};

// Helpers for GridLocation

bool operator == (GridLocation a, GridLocation b) {
    return a.x == b.x && a.y == b.y;
}

bool operator != (GridLocation a, GridLocation b) {
    return !(a == b);
}

bool operator < (GridLocation a, GridLocation b) {
    return std::tie(a.x, a.y) < std::tie(b.x, b.y);
}

std::basic_iostream<char>::basic_ostream& operator<<(std::basic_iostream<char>::basic_ostream& out, const GridLocation& loc) {
    out << '(' << loc.x << ',' << loc.y << ')';
    return out;
}

namespace std {
    /* implement hash function so we can put GridLocation into an unordered_set */
    template <> struct hash<GridLocation> {
        typedef GridLocation argument_type;
        typedef std::size_t result_type;
        std::size_t operator()(const GridLocation& id) const noexcept {
            return std::hash<int>()(id.x ^ (id.y << 4));
        }
    };
}

struct SquareGrid
{
    static std::array<GridLocation, 4> DIRS;
    
    std::unordered_set<GridLocation> walls;
    
    SquareGrid(int width_, int height_): width(width_), height(height_) {}
    
    bool in_bounds(GridLocation id) const {
        return 0 <= id.x && id.x < width
        && 0 <= id.y && id.y < height;
    }
    
    bool passable(GridLocation id) const {
        return walls.find(id) == walls.end();
    }
    
    std::vector<GridLocation> neighbors(GridLocation id) const {
        
        std::vector<GridLocation> results;
        
        for (GridLocation dir : DIRS) {
            GridLocation next{id.x + dir.x, id.y + dir.y};
            if (in_bounds(next) && passable(next)) {
                results.push_back(next);
            }
        }
        
        if ((id.x + id.y) % 2 == 0) {
            // aesthetic improvement on square grids
            std::reverse(results.begin(), results.end());
        }
        
        return results;
    }
    
    int width, height;
};

std::array<GridLocation, 4> SquareGrid::DIRS = {GridLocation{1, 0}, GridLocation{0, -1}, GridLocation{-1, 0}, GridLocation{0, 1}};

#pragma mark - print

// This outputs a grid. Pass in a distances map if you want to print
// the distances, or pass in a point_to map if you want to print
// arrows that point to the parent location, or pass in a path vector
// if you want to draw the path.
template<class Graph>
void draw_grid(const Graph& graph, int field_width,
               std::unordered_map<GridLocation, double>* distances = nullptr,
               std::unordered_map<GridLocation, GridLocation>* point_to = nullptr,
               std::vector<GridLocation>* path=nullptr) {
    for (int y = 0; y != graph.height; ++y) {
        for (int x = 0; x != graph.width; ++x) {
            GridLocation id {x, y};
            std::cout << std::left << std::setw(field_width);
            if (graph.walls.find(id) != graph.walls.end()) {
                std::cout << std::string(field_width, '#');
            } else if (point_to != nullptr && point_to->count(id)) {
                GridLocation next = (*point_to)[id];
                if (next.x == x + 1) { std::cout << "> "; }
                else if (next.x == x - 1) { std::cout << "< "; }
                else if (next.y == y + 1) { std::cout << "v "; }
                else if (next.y == y - 1) { std::cout << "^ "; }
                else { std::cout << "* "; }
            } else if (distances != nullptr && distances->count(id)) {
                std::cout << (*distances)[id];
            } else if (path != nullptr && find(path->begin(), path->end(), id) != path->end()) {
                std::cout << '@';
            } else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
}

void add_rect(SquareGrid& grid, int x1, int y1, int x2, int y2) {
    for (int x = x1; x < x2; ++x) {
        for (int y = y1; y < y2; ++y) {
            grid.walls.insert(GridLocation{x, y});
        }
    }
}

SquareGrid make_diagram1() {
    SquareGrid grid(30, 15);
    add_rect(grid, 3, 3, 5, 12);
    add_rect(grid, 13, 4, 15, 15);
    add_rect(grid, 21, 0, 23, 7);
    add_rect(grid, 23, 5, 26, 7);
    return grid;
}


template<class G>
std::unordered_map<typename G::Location,typename G::Location> breadthFirstSearch(G graph, typename G::Location start)
{
    //typedef typename G::Location Location;
    using Location = typename G::Location;
    
    std::queue<Location> frontier;
    frontier.push(start);
    
    std::unordered_map<Location, Location> came_from;
    came_from[start] = start;
    
    while (!frontier.empty()) {
        auto current = frontier.front();
        frontier.pop();
        //std::cout << "visiting" << current << std::endl;
        
        for (auto & next: graph.neighbors(current))
        {
            // !visited.count(next)
            // исчем контейнер для эл-ов со значениями next
            // возвр 1 если элемент с этим знач существует
            // 0 - не сущ.
            if (!came_from.count(next))
            {
                frontier.push(next);
                came_from[next] = current;
            }
        }
        
    }
    
    return came_from;
}


// test 1
//    Graph<char> testGraph {{
//        {'a', {'b'}},
//        {'b', {'a', 'c', 'd'}},
//        {'c', {'a'}},
//        {'d', {'e', 'a'}},
//        {'e', {'b'}}
//    }};
//
//    breadthFirstSearch(testGraph, 'a');

//    SquareGrid grid = make_diagram1();
//
//    auto parents = breadthFirstSearch(grid, SquareGrid::Location{7, 8});
//
//    draw_grid(grid, 2, nullptr, &parents);

#endif /* iTest_h */
