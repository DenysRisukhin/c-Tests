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

#pragma mark - linear search

bool linear_search(int* arr, int size, int val) {
    for (auto i = 0; i < size; ++i) {
        if (arr[i] == val) {
            return true;
        }
    }
    return false;
}

#pragma mark - binary search

bool binary_serarch(int* arr, int l, int r, int val) {
    while (l < r) {
        int middleIdx = (l + r) / 2;
        
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

#pragma mark - breadthFirstSearch_tree

bool breadthFirstSearch_tree(Node* rootPtr, int val) {
    if (!rootPtr) {
        return false;
    }
    
    std::queue<Node*> queue;
    queue.push(rootPtr);
    
    while (!queue.isempty()) {
        Node* cur = new Node;
        cur = queue.front();
        
        if (cur->data == val) {
            return true;
        } else {
            if (cur->leftPtr) {
                queue.push(cur->leftPtr);
            } else if (cur->rightPtr) {
                queue.push(cur->rightPtr);
            }
        }
    }
    return false;
}

#pragma mark - breadthFirstSearch_graph

template<typename Location>
std::unorderd_map<int, int>  bfs(Graph<int>& graph,int start, int end) {
    std::queue<int> frontier;
    frontier.push(start);
    
    std::unorderd_map<int, int> cameFrom;
    
    while(!frontier.empty()) {
        auto cur = frontier.front();
        frontier.pop();
        
        if (cur == end) {
            break;
        }
        
        for (const auto& neightbor: graph.getNeightbors(cur)) {
            if (!cameFrom.count(neightbor)) {
                frontier.push(neightbor);
                cameFrom[neightbor] = cur;
            }
        }
        return cameFrom;
    }
    
    auto neightbors = graph.getNeightbors(next.m_node);
    for (const auto& neightbor : neightbors) {
        if (!cameFromDFS.count(neightbor.m_node)) {
            dfs(neightbor, graph, cameFromDFS);
        }
    }
}

#pragma mark - depthFirstSearch_graph
template<typename Location>
void dfs(Edge<Location> next, Graph<Location>& graph, std::unordered_map<int, Edge<int>>& cameFromDFS) {
    //if ((graph.getNeightbors(next.m_node)).empty()) {
    //    return; // Это сток графа, путь не найден
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

#endif /* Searching_h */
