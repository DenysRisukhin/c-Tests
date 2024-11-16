//
//  GraphTask_02.h
//  Test2019
//
//  Created by Risukhin Denys on 11/22/23.
//  Copyright © 2023 DenysRisukhin. All rights reserved.
//

#ifndef GraphTask_02_h
#define GraphTask_02_h

// Tasks 2
// implement class template graph with coast
// implement class Edge
// implement class Priority Queue

// task 2_1
// implement method dijkstra
// implement method reconstructPath

// task 2_2
// dfs(start, graph, cameFromDFS);

// task 2_3
// void findAllPath(Edge<Location> start, Edge<Location> goal, Graph<Location>& graph, std::string path)

#pragma mark - Priority Queue

template<typename T, typename priority_t>
class PriorityQueue
{
public:
    using PQElement = std::pair<priority_t, T>;

    bool empty() const { return elements.empty(); }

    // кладем Edge с указанным приоритетом
    inline void put(T item, priority_t priority)
    {
        elements.emplace(priority, item);   // err
    }

    // получаем Edge с наилучшим приоритетом
    T get()
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

#pragma mark - TASKS 2_1______________
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
    
    while (!frontier.empty())
    {
        Edge<Location> current = frontier.get();
        
        if (current.m_node == goal.m_node)
        {
            break;
        }
        
        std::vector< Edge<Location> > neightbors = graph.getNeightbors(current.m_node);
        for (Edge<Location>& neightbor: neightbors)
        {
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
std::vector<Edge<Location>> reconstructPath(Edge<Location> start,
                                            Edge<Location> goal,
                                            std::unordered_map<Location, Edge<Location>>& cameFrom)
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

template<typename Location>
void show(Graph<Location>& graph)
{
    for (const auto &kvp : graph.m_vertex)
    {
        std::cout << kvp.first << "\t: ";
        for (auto v : kvp.second)
        {
            std::cout << v.m_node << " ";
        }
        std::cout << std::endl;
    }
}

#pragma mark - TASKS 2_2______________

template<typename Location>
void dfs(Edge<Location> next, Graph<Location>& graph, std::unordered_map<int, Edge<int>>& cameFromDFS) {
    //if ((graph.getNeightbors(next.m_node)).empty()) {
    //    return; 
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

#pragma mark - TASKS 2_3______________

template<typename Location>
void findAllPath(Edge<Location> start, Edge<Location> goal, Graph<Location>& graph, std::string path) {
    
    // cycle check
    for (auto i = 0; i < path.size(); i++) {
        std::string temp = std::to_string(start.m_node);
        if (path[i] == temp[0]) {
            std::cout << "cicle was founded" << std::endl;
            return;
        }
    }
    
    path += std::to_string(start.m_node) + " ";
    
    if (start.m_node == goal.m_node) {
        std::cout << path << std::endl;
        std::cout << std::endl;
        
        return;
    }
    
    if ((graph.getNeightbors(start.m_node)).empty()) {
        return;
    }
    
    auto neightbors = graph.getNeightbors(start.m_node);
    for (auto neightbor : neightbors) {
        findAllPath(neightbor, goal, graph, path);
    }
}

#pragma mark - TESTS

// Tests
//
//int main() {
//
//    // 1. dijkstra with weight
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

//    cout << "Task 2 dfs" << endl;
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
//    cout << "Task 3 findAllPath" << endl;
//
//    std::string strPath = "-->: ";
//
//    findAllPath(start, end, graph, strPath);

//
//    system("pause");
//
//    return 0;
//}

#endif /* GraphTask_02_h */
