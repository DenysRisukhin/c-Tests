//
//  Description.h
//  Test2019
//
//  Created by Risukhin Denys on 6/7/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Description_h
#define Description_h

// Comparison:

// Separate Chaining: Easier to implement, handles high load factors better, but requires additional memory for the lists.
// collisions occur (i.e., multiple keys hash to the same index), the new key-value pairs are added to the linked list at that index. Your code defines a HashNode class, where each node can point to the next node in the list (m_next), thus forming a linked list.

// Open Addressing: More memory efficient since it uses the array itself to handle collisions, but performance can degrade as the load factor increases.
// Open addressing handles collisions by finding another open slot within the hash table's array itself, usually by probing (linear probing, quadratic probing, or double hashing) for an empty slot. There are no linked lists in open addressing, and every element is stored directly in the array. 


#endif /* Description_h */
