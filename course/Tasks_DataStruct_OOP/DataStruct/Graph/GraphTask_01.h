//
//  GraphTasks.h
//  Test2019
//
//  Created by Risukhin Denys on 11/22/23.
//  Copyright © 2023 DenysRisukhin. All rights reserved.
//

#ifndef GraphTasks_h
#define GraphTasks_h

// Tasks 1
// implement class template graph
// implement method bredthFirstSearch
// implement method reconstructPath

template<typename Location>
class Graph
{
public:
    using map = std::unordered_map<Location, std::vector<Location>>;

    std::vector<Location>& getNeighbors(Location id)
    {
        return m_edges[id];
    }
    
    map m_edges;
};

template<typename Location>
std::unordered_map<Location, Location> bredthFirstSearch(GraphTTT<Location>& graph, const Location startPoint, const Location endPoint)
{
    std::queue<Location> frontier;
    frontier.push(startPoint);
    
    unordered_map<Location, Location> cameFrom;

    while (!frontier.empty())
    {
        Location curPoint = frontier.front();
        frontier.pop();
        
        if (curPoint == endPoint)
        {
            break;
        }
        
        vector<Location> neighbors = graph.getNeighbors(curPoint);
        for (Location& neighbor: neighbors)
        {
            if (!cameFrom.count(neighbor))
            {
                frontier.push(neighbor);
                cameFrom[neighbor] = curPoint;
            }
        }
    }
    
    return cameFrom;
}

template<typename Location>
vector<Location> reconstructPath(Location start, Location goal, unordered_map<Location, Location>& cameFrom)
{
    vector<Location> path;
    Location cur = goal;
    path.push_back(cur);
    
    while (cur != start)
    {
        cur = cameFrom[cur];
        path.push_back(cur);
    }
    
    std::reverse(path.begin(), path.end());
    return path;
}

//int main()
//{
//    GraphTTT<int> graph {{
//        {1, {4, 2}},
//        {2, {3, 8}},
//        {3, {1, 4}},
//        {4, {6, 7}},
//        {5, {2, 3}},
//        {6, {5, 7}},
//        {7, {1, 8}},
//        {8, {5, 6}},
//    }};
//    
//    int startPoint = 4;
//    int endPoint = 2;
//    
//    unordered_map<int, int> cameFrom = bredthFirstSearch(graph, startPoint, endPoint);
//    vector<int> path = reconstructPath(startPoint, endPoint, cameFrom);
//    
//    for (auto i: path)
//    {
//        cout << i << ' ';
//    }
//    
//    cout << endl;
//
//    return 0;
//}



#endif /* GraphTasks_h */
