//
//  PathFinding.hpp
//  Test2019
//
//  Created by Denys Risukhin on 12/26/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef PathFinding_hpp
#define PathFinding_hpp

#include <stdio.h>

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <ctime>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <iterator>
#include <functional>

using namespace std;

// Step 1. class Graph
//        1.1 c-tor
//        1.2 getNeighboars
//            std::vector<Location>& getNeightbors(Location id)

//        1.3 choose struct for points. For example unordered_map
//            std::unordered_map<Location, std::vector<Location>> vertex;
//
//        1.4 use using instead typedef
//            using map = std::unordered_map<Location, std::vector<Location>>;

// Step 2. Put data to graph
// Step 3. Put data to breadthFirstSearch method
// Step 4. Reconstruct path

#pragma mark - Priority Queue

template<typename T, typename priority_t>
class PriorityQueue
{
public:
    using PQElement = std::pair<priority_t, T>;

    inline bool empty() const { return elements.empty(); }

    // кладем Edge с указанным приоритетом
    inline void put(T item, priority_t priority)
    {
        elements.emplace(priority, item);   // err
    }

    // получаем Edge с наилучшим приоритетом
    inline T get()
    {
        T bestItem = elements.top().second;
        elements.pop();
        return bestItem;
    }

    std::priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement>> elements;
};

#pragma mark - Edge

template<typename T>
class Edge
{
public:
    Edge(T node = -1, double weight = 0) : m_node(node), m_weight(weight) {}
    
    Edge(const Edge<T>& obj)
    {
        m_node = obj.m_node;
        m_weight = obj.m_weight;
    }
    
    Edge<T>& operator=(const Edge<T>& obj)
    {
        m_node = obj.m_node;
        m_weight = obj.m_weight;
        
        return *this;
    }
    
    bool operator==(const Edge<T>& obj) const { return m_node == obj.m_node; }
    
    bool operator!=(const Edge<T>& obj) const { return !(*this == obj); }
    
    bool operator<(const Edge<T>& obj) const { return m_node < obj.m_node; }
    
    T m_node;
    double m_weight;
};

#pragma mark - Graph with coastSoFar
// How to write coast
// How to call coast

template <typename Location>
class Graph
{
public:
    using unorderMap = std::unordered_map<Location, std::vector<Edge<Location>>>;
    
    Graph(unorderMap vertex) : m_vertex(vertex) {}
    
    std::vector<Edge<Location>> getNeightbors(Location id) const
    {
        return (m_vertex.find(id))->second;
    }
    
    // { 1, { Edge<int>(4, 4), Edge<int>(2, 5) } },
    double getCost(Edge<Location> fromNode, Edge<Location> toNode)
    {
        auto neightbors = getNeightbors(fromNode.m_node);
        for (auto neightbor: neightbors)
        {
            if (neightbor.m_node == toNode.m_node)
            {
                return toNode.m_weight;
            }
        }
        
        return 0;
    }
    
    unorderMap m_vertex;
};

#pragma mark - dijkstra

template<typename Location>
void dijkstra (
               Graph<Location> graph,
               Edge<Location> start,
               Edge<Location> goal,
               std::unordered_map<Location, Edge<Location>>& cameFrom,
               std::unordered_map<Location, Edge<Location>>& coastSoFar
               )
{
    PriorityQueue<Edge<Location>, double> frontier;
    frontier.put(start, 0);
    
    cameFrom[start.m_node] = start;
    
    Edge<Location> startCost; // m_weight must = 0 // check
    coastSoFar[start.m_node] = startCost;
    
    while (!frontier.empty()) {
        Edge<Location> current = frontier.get();
        
        if (current.m_node == goal.m_node) {
            break;
        }
        
        std::vector< Edge<Location> > neightbors = graph.getNeightbors(current.m_node);
        
        for (Edge<Location>& neightbor: neightbors) {
            
            double currentCost = (coastSoFar.find(current.m_node))->second.m_weight;
            double costFromCurrentToNeighbor = graph.getCost(current, neightbor);
            
            double newCost = currentCost + costFromCurrentToNeighbor;
            
            // если текущего соседа нет в списке coastSoFar или он есть но его вес больше newCost
            // то тогда
            // 1. добавляем этого соседа        в coastSoFar и инициализируем новой стоимостью
            // 2. добавляем этого соседа        в cameFrom
            // 3. кладем этого соседа в очередь frontier  с новым приоритетом
            if (!coastSoFar.count(neightbor.m_node) || (newCost < (coastSoFar.find(current.m_node))->second.m_weight))
            {
                Edge<Location> curCost;
                curCost = neightbor;
                curCost.m_weight = newCost;
                
                coastSoFar[neightbor.m_node] = curCost;
                cameFrom[neightbor.m_node] = current;
                frontier.put(neightbor, newCost);
            }
        }
    }
}

#pragma mark - reconstruct path

template<typename Location>
std::vector<Edge<Location>> reconstructPath(Edge<Location> start, Edge<Location> goal, std::unordered_map<Location, Edge<Location>>& cameFrom)
{
    std::vector<Edge<Location>> path;
    Edge<Location> cur = goal;
    path.push_back(cur);
    
    while (cur != start) {
        cur = cameFrom[cur.m_node];
        path.push_back(cur);
    }
    
    std::reverse(path.begin(), path.end());
    return path;
}



// ‡Î„ÓËÚÏ: Â¯ÂÌËÂ "‚ ÎÓ·" ÂÍÛÒË‚Ì˚Ï ÒÔÛÒÍÓÏ ‰ÓÒÚ‡ÚÓ˜ÌÓ ÔÓÒÚÓÂ.
// ÕÂ Ò‡ÏÓÂ ÓÔÚËÏ‡Î¸ÌÓÂ ÔÓ Ô‡ÏˇÚË Ë ÒÎÓÊÌÓÒÚË, ÌÓ ÍÓÏÔ‡ÍÚÌÓÂ ÔÓ ÍÓ‰Û Ë Ó·˙ˇÒÌÂÌË˛.
// ÓÚ „‡Ù‡ 1 ÔÛÒÍ‡˛ ‚ÂÚ‚Ë(ÔÓ Â·‡Ï) Í ÒÏÂÊÌ˚Ï ‚Â¯ËÌ‡Ï.
// ÓÚ ÌËı ÔÛÒÍ‡˛ ÒÌÓ‚‡ ‚ÂÚ‚Ë Ë Ú‰ ÔÓÍ‡ ÌÂ ‰ÓÈ‰Û ‰Ó ‚Â¯ËÌ˚ n.
// Ò˜ÂÚ˜ËÍÓÏ ÔÂÂÒ˜ËÚ˚‚‡˛ Ë ÓÚ‚ÂÚ „ÓÚÓ‚.

// ŒÚÓ·‡ÁËÏ „‡Ù ‚ Ô‡ÏˇÚ¸ ÒÔËÒÍ‡ÏË ÒÏÂÊÌÓÒÚË ---->>>   unordered_map<int, std::vector<int>> graph;

// “Ó ÂÒÚ¸ ‰Îˇ Í‡Ê‰ÓÈ ÌÓ‰˚ ·Û‰ÂÏ ı‡ÌËÚ¸ ÒÔËÒÓÍ "‰Ó˜ÂÌËı" ÌÓ‰ Ò ÔÓÏÓ˘¸˛ vector.
//  ‡Ê‰ÓÈ ÌÓ‰Â ÒÓÓÚ‚ÂÚÒ‚ÛÂÚ Ò‚ÓÈ ÒÔËÒÓÍ ÒÏÂÊÌÓÒÚË - ËÒÔÓÎ¸ÁÛÂÏ map Ú Í ÏÓÊÌÓ „Ó‚ÓËÚ¸ Ó Ô‡‡ı ÍÎ˛˜ - ÁÌ‡˜ÂÌËÂ,
//         ÍÎ˛˜     - ËÏˇ ÌÓ‰˚,
//         ÁÌ‡˜ÂÌËÂ - vector "‰Ó˜ÂÌËı" ÌÓ‰.

// ÂÍÛÒË‚Ìˇ ÙÛÌÍˆËˇ ÔÓËÒÍ‡

template<typename Location>
void dfs(Edge<Location> next, Graph<Location>& graph, std::unordered_map<int, Edge<int>>& cameFromDFS) {
    //if ((graph.getNeightbors(next.m_node)).empty()) {
    //    return; // ›ÚÓ ÒÚÓÍ „‡Ù‡, ÔÛÚ¸ ÌÂ Ì‡È‰ÂÌ
    //}
    
    cameFromDFS[next.m_node] = next;
    
    std::cout << next.m_node << ' ';
    
    auto neightbors = graph.getNeightbors(next.m_node);
    for (const auto& neightbor : neightbors) {
        if (!cameFromDFS.count(neightbor.m_node)) {
            dfs(neightbor, graph, cameFromDFS);
        }
    }
}

template<typename Location>
void findAllPath(Edge<Location> start, Edge<Location> goal, Graph<Location>& graph, std::string path) {
    
    // cycle check
    for (auto i = 0; i < path.size(); i++) {
        string temp = std::to_string(start.m_node);
        if (path[i] == temp[0]) {
            cout << "cicle was founded" << endl;
            return;
        }
    }
    
    path += std::to_string(start.m_node) + " "; // ‰Ó·‡‚ÎˇÂÏ ‚ ÔÛÚ¸ ÚÂÍÛ˘Û˛ ÌÓ‰Û
    
    if (start.m_node == goal.m_node) {
        //ÔÛÚ¸ Ì‡È‰ÂÌ, ÔÂ˜‡Ú‡ÂÏ Ë ‚ÓÁ‚‡˘‡ÂÏÒˇ.
        std::cout << path << std::endl;
        std::cout << std::endl;
        
        return;
    }
    
    // Í‡ÍˇÚÓ ÍÓÌÂ˜Ì‡ˇ ÚÓ˜Í‡ ·ÂÁ ÔÂÂıÓ‰Ó‚ Ì‡ ÌÓ‚˚È ÛÁÎ˚
    if ((graph.getNeightbors(start.m_node)).empty()) {
        return; // ›ÚÓ ÒÚÓÍ „‡Ù‡, ÔÛÚ¸ ÌÂ Ì‡È‰ÂÌ
    }
    
    auto neightbors = graph.getNeightbors(start.m_node);
    for (auto neightbor : neightbors) {
        findAllPath(neightbor, goal, graph, path);
    }
}

template<typename Location>
void show(Graph<Location>& graph)
{
    //‚˚‚Ó‰ ÚÂÍÛ˘Ëı ÒÔËÒÍÓ‚ ÒÏÂÊÌÓÒÚË ‚ ˜ËÚ‡·ÂÎ¸ÌÓÏ ‚Ë‰Â.
    
    //for (const auto &kvp : graph.m_vertex)
    //{
    //    std::cout << kvp.first << "\t: ";
    //    for (auto v : kvp.second)
    //        std::cout << v << " ";
    //    std::cout << std::endl;
    //}
}


// Tests
//
//int main() {
//
//    vector<int> vec{ 34, 5, 44, 54 };
//
//
//    /*for (const auto& i: vec) {
//
//     }*/
//    for (auto i: vec) {
//        i = 1;
//        //cout << i << ' ';
//    }
//
//    for (auto i : vec) {
//        cout << i << ' ';
//    }
//
//
//
//    cout << endl << endl;
//
//    // 2. dijkstra with weight
//    // TO DO
//    // draw on the pic & set correct weight
//    Graph<int> graph{ {
//        { 1, { Edge<int>(4, 4), Edge<int>(2, 5) } },
//        { 2, { Edge<int>(3, 6), Edge<int>(8, 5) } },
//        { 3, { Edge<int>(1, 5), Edge<int>(4, 2) } },
//        { 4, { Edge<int>(6, 2), Edge<int>(7, 3) } },
//        { 5, { Edge<int>(2, 3), Edge<int>(3, 7) } }, // 7 ÏÂÌˇÂÏ Ì‡ 100 Ë ÔÛÚ¸ ËÁÏÂÌˇÂÚÒˇ
//        { 6, { Edge<int>(5, 3), Edge<int>(7, 2) } },
//        { 7, { Edge<int>(1, 5), Edge<int>(8, 5) } },
//        { 8, { Edge<int>(5, 1), Edge<int>(6, 4) } }
//    } };
//
//    //show(graph);
//
//    Edge<int> start(1);
//    Edge<int> end(4);
//
//    std::unordered_map<int, Edge<int>> cameFrom;
//    std::unordered_map<int, Edge<int>> coastSoFar;
//
//    dijkstra(graph, start, end, cameFrom, coastSoFar);
//
//    std::vector<Edge<int>> path = reconstructPath(start, end, cameFrom);
//
//    for (auto i: path) {
//        std::cout << i.m_node << ' ';
//    }
//
//    std::cout << std::endl;
//
//    cout << "Task 3 findAllPath" << endl;
//
//    std::string strPath = "-->: ";
//
//    findAllPath(start, end, graph, strPath);
//
//    cout << "Task 4 dfs" << endl;
//    std::unordered_map<int, Edge<int>> cameFromDFS;
//
//    dfs(start, graph, cameFromDFS);
//
//    //path = reconstructPath(start, end, cameFrom);
//
//    /*for (auto i : path) {
//     std::cout << i.m_node << ' ';
//     }*/
//
//    system("pause");
//
//    return 0;
//}

#endif /* PathFinding_hpp */
