//
//  Tree_6.h
//  Test2019
//
//  Created by Risukhin Denys on 1/19/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Tree_6_h
#define Tree_6_h

//If you're specifically working with trees and are concerned about memory usage, some considerations come into play. Here are a few tree-related search algorithms and structures that are memory-efficient:

//1. Breadth-First Search (BFS):
//Requires a queue to keep track of nodes at the current level.
//Consumes memory proportional to the width of the tree at the widest level.
//Memory usage is generally less compared to depth-first search for wide trees.
//
//2. Depth-First Search (DFS):
//Uses a stack or recursion to traverse the tree.
//Consumes memory proportional to the depth of the tree.
//Recursive DFS might have higher memory overhead due to the call stack.
//
//3. Iterative Deepening Depth-First Search (IDDFS):
//A combination of BFS and DFS.
//Provides depth-first exploration with a controlled memory footprint.
//Useful for scenarios where BFS memory requirements are too high.

// If we are looking for a memory-efficient search algorithm for a tree with a height of 300,000, you might want to consider an iterative deepening depth-first search (IDDFS) approach. IDDFS is a combination of depth-first search (DFS) and breadth-first search (BFS) that aims to provide the advantages of both while keeping the memory footprint under control.



#endif /* Tree_6_h */
