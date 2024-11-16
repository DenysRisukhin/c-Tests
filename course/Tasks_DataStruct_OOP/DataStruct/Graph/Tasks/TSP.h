//
//  TSP.h
//  Test2019
//
//  Created by Risukhin Denys on 6/21/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef TSP_h
#define TSP_h

#include <iostream>
#include <vector>
#include <limits>
#include <memory> // For smart pointers

using namespace std;

constexpr int INF = numeric_limits<int>::max();

class Graph {
private:
    int m_numCities;
    vector<vector<int>> m_adjMatrix;

public:
    // Default constructor
    Graph(int numCities) : m_numCities(numCities), m_adjMatrix(numCities, vector<int>(numCities, 0)) {}

    // Move constructor
    Graph(Graph&& other) noexcept
        : m_numCities(other.m_numCities), m_adjMatrix(move(other.m_adjMatrix)) {
        other.m_numCities = 0;
    }

    // Move assignment operator
    Graph& operator=(Graph&& other) noexcept {
        if (this != &other) {
            m_numCities = other.m_numCities;
            m_adjMatrix = move(other.m_adjMatrix);
            other.m_numCities = 0;
        }
        return *this;
    }

    void addEdge(int from, int to, int weight) {
        m_adjMatrix[from][to] = weight;
        m_adjMatrix[to][from] = weight;
    }

    int getEdgeWeight(int from, int to) const {
        return m_adjMatrix[from][to];
    }

    int numCities() const {
        return m_numCities;
    }
};

// Function to find the minimum cost
int tsp(int visitedCitiesMask, int currentCity, const Graph& graph, vector<vector<int>>& dp) {
    const int numCities = graph.numCities();
    const int allCitiesVisited = (1 << numCities) - 1; // Mask when all cities have been visited

    // All cities have been visited, return to the starting city
    if (visitedCitiesMask == allCitiesVisited) {
        return graph.getEdgeWeight(currentCity, 0);
    }

    // Return the stored result if already computed
    if (dp[visitedCitiesMask][currentCity] != -1) {
        return dp[visitedCitiesMask][currentCity];
    }

    int minCost = INF;

    // Try to visit all unvisited cities
    for (int nextCity = 0; nextCity < numCities; ++nextCity) {
        if (!(visitedCitiesMask & (1 << nextCity))) { // If the nextCity has not been visited
            int newMask = visitedCitiesMask | (1 << nextCity);
            int costToNextCity = graph.getEdgeWeight(currentCity, nextCity);
            int costToVisitNextCity = tsp(newMask, nextCity, graph, dp);
            int newCost = costToNextCity + costToVisitNextCity;
            minCost = min(minCost, newCost);
        }
    }

    // Store and return the result
    dp[visitedCitiesMask][currentCity] = minCost;
    return minCost;
}

//int main() {
//    int numCities;
//    cout << "Enter the number of cities: ";
//    cin >> numCities;
//
//    // Create graph object using smart pointer for better memory management
//    auto graph = make_shared<Graph>(numCities);
//
//    cout << "Enter the distance matrix:\n";
//    for (int i = 0; i < numCities; ++i) {
//        for (int j = 0; j < numCities; ++j) {
//            int weight;
//            cin >> weight;
//            graph->addEdge(i, j, weight);
//        }
//    }
//
//    vector<vector<int>> dp(1 << numCities, vector<int>(numCities, -1));
//
//    int result = tsp(1, 0, *graph, dp);
//    cout << "The minimum cost to visit all cities is: " << result << endl;
//
//    return 0;
//}


///


//Explanation
//Move Constructor (Graph&& other)
//
//The move constructor transfers ownership of other's resources (like m_adjMatrix) to the newly constructed object.
//It sets m_numCities to other.m_numCities and invalidates other's resources (in this case, sets m_numCities to 0).
//Move Assignment Operator (operator=(Graph&& other))
//
//The move assignment operator transfers ownership of resources from other to this object.
//It first checks for self-assignment (this != &other) and then moves m_adjMatrix and m_numCities from other to this.
//After transfer, it invalidates other's resources by setting m_numCities to 0.
//Benefit of Move Semantics
//
//Move semantics improve performance by efficiently transferring resources instead of copying them.
//This is particularly useful for large objects (like matrices) where copying can be expensive in terms of time and memory.
//Main Function
//
//Uses make_shared to create the Graph object, ensuring efficient memory allocation and management.
//Computes the minimum tour cost using the tsp function with improved memory handling through move semantics.
//Compilation and Execution
//Compile and execute the program as usual:
//Compile with: g++ -o tsp tsp.cpp.
//Execute with: ./tsp.
//Enter the number of cities and the distance matrix as prompted.
//This updated implementation with move semantics enhances efficiency and maintains good object-oriented design principles,
//making it suitable for professional development and coding interviews.

#endif /* TSP_h */
