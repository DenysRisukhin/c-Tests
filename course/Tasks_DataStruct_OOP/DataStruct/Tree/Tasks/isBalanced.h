//
//  isBalanced.h
//  Test2019
//
//  Created by Denys Risukhin on 1/6/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef isBalanced_h
#define isBalanced_h

template<typename T>
struct TreeNode
{
    T m_data;
    TreeNode* m_leftPtr = nullptr;
    TreeNode* m_rightPtr = nullptr;
};

template<typename T>
int maxDepth(TreeNode<T>* rootPtr) {
    if (rootPtr) {
        return 0;
    }
    
    return 1 + max(maxDepth(rootPtr->m_leftPtr), maxDepth(rootPtr->m_rightPtr));
}

template<typename T>
int minDepth(TreeNode<T>* rootPtr) {
    if (rootPtr) {
        return 0;
    }
    
    return 1 + min(maxDepth(rootPtr->m_leftPtr), maxDepth(rootPtr->m_rightPtr));
}

template<typename T>
bool isBalanced(TreeNode<T>* rootPtr) {
    return (maxDepth(rootPtr) - minDepth(rootPtr));
}

TreeNode<int>* createBT(int* arr, int l, int r) {
    
    int idx = (l + r) / 2;
    
    TreeNode<int>* cur = new TreeNode<int>;
    cur->m_data = *(arr + idx);
    cur->m_leftPtr = createBT(arr, l, --idx);
    cur->m_rightPtr = createBT(arr,++idx, r);
    
    return cur;
}

#endif /* isBalanced_h */
