//
//  list_2.h
//  Test2019
//
//  Created by Denys Risukhin on 2/9/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef list_2_h
#define list_2_h

struct LinkedListNode
{
    int m_value;
    LinkedListNode* m_next = nullptr;
};

void push(LinkedListNode** head, int val)
{
    LinkedListNode* newNode = new LinkedListNode;
    newNode->m_value = val;
    newNode->m_next = (*head);
    (*head) = newNode;
}

LinkedListNode* merge(LinkedListNode* nodeA, LinkedListNode* nodeB)
{
    LinkedListNode* resNode = nullptr;
    
    if (!nodeA)
    {
        resNode->m_next = nodeB;
        return resNode;
    }
    else if (!nodeB)
    {
        resNode->m_next = nodeA;
        return resNode;
    }
    
    if (nodeA->m_value <= nodeB->m_value)
    {
        resNode = nodeA;
        resNode->m_next = merge(nodeA->m_next, nodeB);
    }
    else
    {
        resNode = nodeB;
        resNode->m_next = merge(nodeA, nodeB->m_next);
    }
    
    return resNode;
}

// tests

//LinkedListNode* resNode = nullptr;
//LinkedListNode* aNode = nullptr;
//LinkedListNode* bNode = nullptr;
//
//push(&aNode, 15);
//push(&aNode, 10);
//push(&aNode, 5);
//
//push(&bNode, 20);
//push(&bNode, 3);
//push(&bNode, 2);
//
//resNode = merge(aNode, bNode);
//
//cout << endl;

#endif /* list_2_h */
