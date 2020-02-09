//
//  list_1.h
//  Test2019
//
//  Created by Denys Risukhin on 2/9/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef list_1_h
#define list_1_h

struct LinkedListNode
{
    int m_value;
    LinkedListNode* m_next = nullptr;
};

bool checkLinkedList(LinkedListNode* firstItem)
{
    if (!firstItem)
    {
        return false;
    }
    
    LinkedListNode* firstNode = firstItem;
    LinkedListNode* nextNode = firstItem->m_next;
    
    while (nextNode->m_next != nullptr)
    {
        if (nextNode->m_next == firstNode)
        {
            return true;
        }
        
        nextNode = nextNode->m_next;
    }
    
    return false;
}

#endif /* list_1_h */
