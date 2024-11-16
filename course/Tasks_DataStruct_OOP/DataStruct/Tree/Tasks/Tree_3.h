//
//  Tree_3.h
//  Test2019
//
//  Created by Risukhin Denys on 1/19/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Tree_3_h
#define Tree_3_h

template<typename T>
struct TreeNode
{
    TreeNode(const T& data): m_data(data) {}
    
    TreeNode* m_leftPtr = nullptr;
    TreeNode* m_rightPtr = nullptr;
    TreeNode* m_parentPtr = nullptr;
    
    T m_data;
};

TreeNode<T>* createNewNode(int data)
{
    TreeNode* tempNodePtr = new TreeNode(data);
    //tempNodePtr->m_data = data;
    tempNodePtr->m_parent = tempNodePtr->m_leftPtr = tempNodePtr->m_rightPtr = nullptr;
    return tempNodePtr;
}

TreeNode<T>* insert(TreeNode<T>* nodePtr, int data)
{
    if (!nodePtr)
    {
        return createNewNode(data);
    }
    
    if (data < nodePtr->m_data)
    {
        nodePtr->m_leftPtr = insert(nodePtr->m_leftPtr, data);
        nodePtr->m_leftPtr->m_parentPtr = nodePtr;
    }
    else if (data > nodePtr->m_data)
    {
        nodePtr->m_rightPtr = insert(nodePtr->m_rightPtr, data);
        nodePtr->m_rightPtr->m_parentPtr = nodePtr;
    }
    
    return nodePtr;
}

#pragma mark - main logic

template<typename T>
int getDepth(TreeNode<T>* node)
{
    int depth = 0;
    
    while (node->m_parentPtr)
    {
        node = node->m_parentPtr;
        depth++;
    }
    return depth;
}

template<typename T>
TreeNode<T>* getCommonAncestor(TreeNode<T>* n1, TreeNode<T>* n2)
{
    int diff = getDepth(n1) - getDepth(n2);
    
    if (diff < 0)
    {
        auto tempTreeNode = n1;
        n1 = n2;
        n2 = tempTreeNode;
    }
    
    while (diff--)
    {
        n1 = n1->m_parentPtr;
    }
    
    while (n1 && n2)
    {
        if (n1->m_data == n2->m_data)
        {
            return n1;
        }
        
        n1 = n1->m_parentPtr;
        n2 = n2->m_parentPtr;
    }
    
    return nullptr;
}

//test
//TreeNode* rootNodePtr = nullptr;
//rootNodePtr = insert(rootNodePtr, 20);
//rootNodePtr = insert(rootNodePtr, 8);
//rootNodePtr = insert(rootNodePtr, 22);
//rootNodePtr = insert(rootNodePtr, 4);
//rootNodePtr = insert(rootNodePtr, 12);
//rootNodePtr = insert(rootNodePtr, 10);
//rootNodePtr = insert(rootNodePtr, 14);
//
//TreeNode* nodeAPtr = rootNodePtr->m_leftPtr->m_rightPtr->m_leftPtr;
//TreeNode* nodeBPtr = rootNodePtr->m_rightPtr;
//
//TreeNode* lca = getCommonAncestor(nodeAPtr, nodeBPtr);


#endif /* Tree_3_h */
