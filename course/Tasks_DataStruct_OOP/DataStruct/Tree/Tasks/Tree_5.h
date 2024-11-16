//
//  Tree_5.h
//  Test2019
//
//  Created by Risukhin Denys on 1/19/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Tree_5_h
#define Tree_5_h

struct TreeNode
{
    TreeNode(): m_leftPtr(nullptr), m_rightPtr(nullptr), m_data(0) {}
    TreeNode(int data): m_leftPtr(nullptr), m_rightPtr(nullptr), m_data(data) {}
    
    TreeNode* m_leftPtr = nullptr;
    TreeNode* m_rightPtr = nullptr;
    int m_data;
};

void inserNode(TreeNode*& root, int data)
{
    if (root == nullptr)
    {
        root = new TreeNode;
        root->m_data = data;
        root->m_leftPtr = nullptr;
        root->m_rightPtr = nullptr;
    }
    else if (data < root->m_data)
    {
        inserNode(root->m_leftPtr, data);
    }
    else
    {
        inserNode(root->m_rightPtr, data);
    }
}

void setSum(TreeNode* root, int& sum)
{
    if (root)
    {
        sum += root->m_data;
        setSum(root->m_leftPtr, sum);
        setSum(root->m_rightPtr, sum);
    }
}

// test

//    TreeNode* root = nullptr;
//    int sum = 0;
//
//    for (int i = 1; i <= 6; i++) {
//        inserNode(root, i);
//    }
//
//    setSum(root, sum);
//
//    cout << sum << endl;
//
//    cout << endl;



#endif /* Tree_5_h */
