//
//  Searching.h
//  Test2019
//
//  Created by Denys Risukhin on 9/24/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef Searching_h
#define Searching_h

#include <queue>
#include <unorderd_map>
#include <iostream>

linearSearch                O(n)
binarySearch                O(log(n))

breadthFirstSearch_tree     O(n)

breadthFirstSearch_graph    O(V + E)
    V is the number of vertices
    E is the number of edges in the graph.

depthFirstSearch_graph      O(V + E)
    considering the traversal and storing of paths


#pragma mark - linear search ###########################################################################################

bool linear_search(int* arr, int size, int val) {
    for (auto i = 0; i < size; ++i) {
        if (arr[i] == val) {
            return true;
        }
    }
    return false;
}

void printResult(bool result, int val, const std::string& searchType) {
    if (result) {
        std::cout << searchType << ": Value " << val << " found in the array." << std::endl;
    } else {
        std::cout << searchType << ": Value " << val << " not found in the array." << std::endl;
    }
}

// TEST

//int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//int n = sizeof(arr) / sizeof(arr[0]);
//
//// Test cases for linear search
//    int linearTestValues[] = {5, 11, 1, 10};
//    for (int val : linearTestValues) {
//        bool result = linear_search(arr, n, val);
//        printResult(result, val, "Linear Search");
//    }

#pragma mark - binary search ###########################################################################################

bool binary_serarch(int* arr, int l, int r, int val)
{
    while (l <= r) {
        int middleIdx = (l + r) / 2;
        //int middleIdx = l + (r - l) / 2;  // To avoid overflow, calculate middle index like this
        
        if (arr[middleIdx] == val) {
            return true;
        } else if (val < arr[middleIdx]) {
            r = --middleIdx;
        } else if (arr[middleIdx] < val) {
            l = ++middleIdx;
        }
    }
    
    return false;
}

// TEST

//int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//int n = sizeof(arr) / sizeof(arr[0]);
//
//// Test cases
//int testValue1 = 5;
//bool result1 = binary_search(arr, 0, n - 1, testValue1);
//printResult(result1, testValue1);
//
//int testValue2 = 11;
//bool result2 = binary_search(arr, 0, n - 1, testValue2);
//printResult(result2, testValue2);
//
//int testValue3 = 1;
//bool result3 = binary_search(arr, 0, n - 1, testValue3);
//printResult(result3, testValue3);
//
//int testValue4 = 10;
//bool result4 = binary_search(arr, 0, n - 1, testValue4);
//printResult(result4, testValue4);

#pragma mark - breadthFirstSearch_tree ###########################################################################################
// there's no recursion in this breadth-first search (BFS) implementation. The BFS algorithm iteratively visits each node level by level,
// using a queue data structure, rather than using recursion.

//Initialization: O(1)
//Iteration through Nodes: In the worst-case scenario, where every node is visited once, this takes O(n) time, where n is the number of nodes in the tree.
//Queue Operations: Each node is enqueued and dequeued at most once, so the total time spent on queue operations is also O(n).

struct Node
{
    int data;
    Node* leftPtr;
    Node* rightPtr;

    Node(int value) : data(value), leftPtr(nullptr), rightPtr(nullptr) {}
};

// Function to insert nodes in level order
Node* insertLevelOrder(std::vector<int> arr, int i, int n) {
    Node* root = nullptr;
    if (i < n) {
        root = new Node(arr[i]);

        // Insert left child
        root->leftPtr = insertLevelOrder(arr, 2 * i + 1, n);

        // Insert right child
        root->rightPtr = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

bool breadthFirstSearch_tree(Node* rootPtr, int val) {
    if (!rootPtr)
    {
        return false;
    }

    std::queue<Node*> queue;
    queue.push(rootPtr);

    while (!queue.isempty())
    {
        Node* cur = queue.front();
        
        if (cur->data == val) {
            return true;
        }
        
        if (cur->leftPtr) {
            queue.push(cur->leftPtr);
        }
        
        if (cur->rightPtr) {
            queue.push(cur->rightPtr);
        }
    }
    return false;
}

// Helper function to print the result
void printResult(bool result, int val) {
    if (result) {
        std::cout << "Value " << val << " found in the tree." << std::endl;
    } else {
        std::cout << "Value " << val << " not found in the tree." << std::endl;
    }
}

// Test
//    // Constructing the binary tree
//    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
//    Node* root = insertLevelOrder(arr, 0, arr.size());
//
//    // Test cases
//    int testValue1 = 5;
//    bool result1 = breadthFirstSearch_tree(root, testValue1);
//    printResult(result1, testValue1);
//
//    int testValue2 = 8;
//    bool result2 = breadthFirstSearch_tree(root, testValue2);
//    printResult(result2, testValue2);

#pragma mark - breadthFirstSearch_graph ###########################################################################################

//The provided algorithm is an implementation of breadth-first search (BFS) for finding the shortest path in an unweighted graph. Let's analyze its time complexity:
//
//Initialization: O(1) - Initializing the queue and the cameFrom map takes constant time.
//Iteration through Nodes: In the worst-case scenario, each node in the graph is visited once. Since each node is added to the queue at most once, and each node is processed in constant time, the time complexity of this part is O(V), where V is the number of vertices in the graph.
//Processing Neighbors: For each vertex, its neighbors are iterated through. In the worst case, each neighbor of each vertex is examined once. Since each neighbor is processed in constant time, this part contributes O(E) to the overall time complexity, where E is the number of edges in the graph.
//Total Time Complexity: Combining the complexities from the above steps, the overall time complexity of this BFS algorithm is O(V + E), where V is the number of vertices and E is the number of edges in the graph.
//Additionally, there's a small correction needed in the code: std::unorderd_map should be std::unordered_map.

template<typename Location>
class GraphTTT
{
public:
    using map = std::unordered_map<Location, std::vector<Location>>;

    // Default constructor
    GraphTTT() = default;

    // Constructor with initializer list
    explicit GraphTTT(const map& edges)
        : m_edges(edges)
    {
        cout << "Constructor with initializer list" << endl;
    }

    // Copy constructor
    GraphTTT(const GraphTTT& other)
        : m_edges(other.m_edges) {}

    // Copy assignment operator
    GraphTTT& operator=(const GraphTTT& other)
    {
        if (this != &other) {
            m_edges = other.m_edges;
        }
        return *this;
    }

    // Move constructor
    GraphTTT(GraphTTT&& other) noexcept
        : m_edges(std::move(other.m_edges)) {}

    // Move assignment operator
    GraphTTT& operator=(GraphTTT&& other) noexcept
    {
        if (this != &other) {
            m_edges = std::move(other.m_edges);
        }
        return *this;
    }

    // Method to get neighbors
    std::vector<Location>& getNeighbors(Location id)
    {
        return m_edges[id];
    }

    // Method to get the entire map
    const map& getEdges() const
    {
        return m_edges;
    }

    // Method to set edges
    void setEdges(const map& edges)
    {
        m_edges = edges;
    }

private:
    map m_edges;
};


template<typename Location>
std::unordered_map<Location, Location> bredthFirstSearch(GraphTTT<Location>& graph, const Location startPoint, const Location endPoint)
{
    std::queue<Location> frontier; // пограничный
    frontier.push(startPoint);
    
    unordered_map<Location, Location> cameFrom;

    while (!frontier.empty())
    {
        Location curPoint = frontier.front(); // получить значение
        frontier.pop();                       // извлеч значение
        
        if (curPoint == endPoint)
        {
            break;
        }
        
        vector<Location> neighbors = graph.getNeighbors(curPoint);
        for (Location& neighbor: neighbors)
        {
            const bool isNeighborHasAlreadyVisited = static_cast<bool>(cameFrom.count(neighbor));
            //if (!cameFrom.count(neighbor))
            if (isNeighborHasAlreadyVisited == false)
            {
                frontier.push(neighbor);
                cameFrom[neighbor] = curPoint;
            }
        }
    }
    
    return cameFrom;
}

#pragma mark - depthFirstSearch_graph (пошук в глибину) ###########################################################################################

template<typename Location>
void dfsHelper(GraphTTT<Location>& graph, const Location& curPoint, const Location& endPoint, std::unordered_map<Location, Location>& cameFrom)
{
    if (curPoint == endPoint)
    {
        return; // Endpoint found, return to unwind the stack
    }

    std::vector<Location> neighbors = graph.getNeighbors(curPoint);
    for (const Location& neighbor : neighbors)
    {
        auto iter = cameFrom.find(neighbor);
        if (iter == cameFrom.end()) // If the neighbor has not been visited
        {
            cameFrom[neighbor] = curPoint; // Record the path
            dfsHelper(graph, neighbor, endPoint, cameFrom);
            // No need to check for endpoint again here, just continue the recursion
        }
    }
}

template<typename Location>
std::unordered_map<Location, Location> depthFirstSearch(GraphTTT<Location>& graph, const Location startPoint, const Location endPoint)
{
    std::unordered_map<Location, Location> cameFrom; // To keep track of the path
    cameFrom[startPoint] = startPoint; // Start point's parent is itself
    
    dfsHelper(graph, startPoint, endPoint, cameFrom); // Start the recursive DFS
    
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

// Test

//        // Using the initializer list constructor
//  GraphTTT<int> graph({
//    {1, {4, 2}},
//    {2, {3, 8}},
//    {3, {1, 4}},
//    {4, {6, 7}},
//    {5, {2, 3}},
//    {6, {5, 7}},
//    {7, {1, 8}},
//    {8, {5, 6}}
//  });
//
//// Using the copy constructor
//  GraphTTT<int> copiedGraph = graph;
//
//// Using the move constructor
//  GraphTTT<int> movedGraph = std::move(graph);
//
//// Using the copy assignment operator
//  GraphTTT<int> anotherGraph;
//  anotherGraph = copiedGraph;
//
//// Using the move assignment operator
//  GraphTTT<int> yetAnotherGraph;
//  yetAnotherGraph = std::move(movedGraph);
//
//  auto& neighbors = anotherGraph.getNeighbors(1);
//  for (const auto& neighbor : neighbors) {
//    std::cout << neighbor << " ";
//  }
//  std::cout << std::endl;
//
//// Getting the entire map
//  const auto& edges = anotherGraph.getEdges();
//  for (const auto& [node, neighbors] : edges) {
//    std::cout << "Node " << node << ": ";
//    for (const auto& neighbor : neighbors) {
//        std::cout << neighbor << " ";
//    }
//    std::cout << std::endl;
//  }
//
//        int startPoint = 4;
//        int endPoint = 2;
//
//        // unordered_map<int, int> cameFrom = bredthFirstSearch(graph, startPoint, endPoint);
//
//        unordered_map<int, int> cameFrom = depthFirstSearch(graph, startPoint, endPoint);
//
//        vector<int> path = reconstructPath(startPoint, endPoint, cameFrom);
//
//        for (auto i: path)
//        {
//            cout << i << ' ';
//        }
//
//        cout << endl;

#endif /* Searching_h */
