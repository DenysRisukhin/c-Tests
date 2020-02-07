//
//  Tree_4.h
//  Test2019
//
//  Created by Denys Risukhin on 2/5/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef Tree_4_h
#define Tree_4_h

struct TreeNode
{
    TreeNode(): m_leftPtr(nullptr), m_rightPtr(nullptr), m_data(0) {}
    TreeNode(int data): m_leftPtr(nullptr), m_rightPtr(nullptr), m_data(data) {}
    
    TreeNode* m_leftPtr = nullptr;
    TreeNode* m_rightPtr = nullptr;
    int m_data;
};

#pragma mark - a

void nodesOnLevel(const TreeNode* root, int& curLevel, int level, TreeNode*& listHeader, TreeNode*& curListNode)
{
    if (root)
    {
        if (curLevel == level)
        {
            TreeNode* newListNode = new TreeNode(root->m_data);
            
            if (listHeader)
            {
                curListNode->m_leftPtr = newListNode;
            }
            else
            {
                listHeader = newListNode;
            }
            
            curListNode = newListNode;
        }
        
        curLevel++;
        
        if (root->m_leftPtr && curLevel)
        {
            nodesOnLevel(root->m_leftPtr, curLevel, level, listHeader, curListNode);
        }
        
        if (root->m_rightPtr && curLevel)
        {
            nodesOnLevel(root->m_rightPtr, curLevel, level, listHeader, curListNode);
        }
        
        curLevel--;
    }
}

#pragma mark - b

void nodesOnLevel(TreeNode* root, int& curLevel, int level, vector<TreeNode*>& nodesList)
{
    if (root)
    {
        if (curLevel == level)
        {
            nodesList.push_back(root);
        }
        
        curLevel++;
        
        if (root->m_leftPtr)
        {
            nodesOnLevel(root->m_leftPtr, curLevel, level, nodesList);
        }
        
        if (root->m_rightPtr)
        {
            nodesOnLevel(root->m_rightPtr, curLevel, level, nodesList);
        }
        
        curLevel--;
    }
}

vector<TreeNode*> nodesOnLevelCall(TreeNode* root, int level)
{
    vector<TreeNode*> nodesList;
    int curLevel = 0;
    
    nodesOnLevel(root, curLevel, level, nodesList);
    
    return nodesList;
}

//test

//          5
//    3           7
//  1  4        6   8
//       10
//     12  13

// level 2: 1 4 6 8

//TreeNode node0(5);
//TreeNode node1(3);
//TreeNode node2(7);
//TreeNode node3(1);
//TreeNode node4(4);
//TreeNode node5(6);
//TreeNode node6(8);
//TreeNode node7(10);
//TreeNode node8(12);
//TreeNode node9(13);
//
//node0.m_leftPtr = &node1;
//node0.m_rightPtr = &node2;
//node1.m_leftPtr = &node3;
//node1.m_rightPtr = &node4;
//node2.m_leftPtr = &node5;
//node2.m_rightPtr = &node6;
//node4.m_leftPtr = &node7;
//node7.m_rightPtr = &node8;
//node7.m_rightPtr = &node9;
//
// a
//
//TreeNode* listHeader = nullptr;
//TreeNode* curListNode = nullptr;
//
//int curLevel = 0;
//
//nodesOnLevel(&node0, curLevel, 2, listHeader, curListNode);
//
//TreeNode* tempListNode = nullptr;
//tempListNode = listHeader;
//
// print & remove
//while (listHeader != nullptr)
//{
//    cout << listHeader->m_data << ' ';
//
//    tempListNode = listHeader;
//    listHeader = listHeader->m_leftPtr;
//
//    delete tempListNode;
//
//    }
//
//    cout << endl;
//
//    // b
//
//    vector<TreeNode*> nodesList = nodesOnLevelCall(&node0, 2);
//
//    for (auto node: nodesList)
//    {
//        cout << node->m_data << ' ';
//    }
//
//
//    cout << endl;
#endif /* Tree_4_h */
