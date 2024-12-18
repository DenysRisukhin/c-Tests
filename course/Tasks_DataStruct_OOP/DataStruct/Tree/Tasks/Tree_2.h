//
//  Tree_2.h
//  Test2019
//
//  Created by Risukhin Denys on 1/19/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Tree_2_h
#define Tree_2_h

template<typename T>
struct TreeNode
{
    T m_data;
    TreeNode* m_leftPtr = nullptr;
    TreeNode* m_rightPtr = nullptr;
};

TreeNode<int>* createBT(int* arr, int l, int r)
{
    
    int idx = (l + r) / 2;
    
    TreeNode<int>* cur = new TreeNode<int>;
    cur->m_data = *(arr + idx);
    cur->m_leftPtr = createBT(arr, l, --idx);
    cur->m_rightPtr = createBT(arr,++idx, r);
    
    return cur;
}

#pragma mark - main logic

template<typename T>
int maxDepth(TreeNode<T>* rootPtr)
{
    if (rootPtr) {
        return 0;
    }
    
    return 1 + max(maxDepth(rootPtr->m_leftPtr), maxDepth(rootPtr->m_rightPtr));
}

template<typename T>
int minDepth(TreeNode<T>* rootPtr)
{
    if (rootPtr) {
        return 0;
    }
    
    return 1 + min(minDepth(rootPtr->m_leftPtr), minDepth(rootPtr->m_rightPtr));
}

template<typename T>
bool isBalanced(TreeNode<T>* rootPtr)
{
    return (maxDepth(rootPtr) - minDepth(rootPtr));
}


#endif /* Tree_2_h */
