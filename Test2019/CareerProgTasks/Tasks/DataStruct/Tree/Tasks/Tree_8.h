//
//  Tree_8.h
//  Test2019
//
//  Created by Denys Risukhin on 2/7/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef Tree_8_h
#define Tree_8_h

struct TreeNode
{
    TreeNode(): m_leftPtr(nullptr), m_rightPtr(nullptr), m_data(0) {}
    TreeNode(int data): m_leftPtr(nullptr), m_rightPtr(nullptr), m_data(data) {}
    
    TreeNode* m_leftPtr = nullptr;
    TreeNode* m_rightPtr = nullptr;
    int m_data;
};

TreeNode* addToBST(const vector<int>& numbers, const int& start, const int& end)
{
    if (end < start)
    {
        return nullptr;
    }
    
    int middle = (start + end) / 2;
    
    TreeNode* newNode = new TreeNode;
    newNode->m_data = numbers[middle];
    newNode->m_leftPtr = addToBST(numbers, start, middle - 1);
    newNode->m_rightPtr = addToBST(numbers, middle + 1, end);
    
    return newNode;
}

TreeNode* createMinimalBST(vector<int> numbers)
{
    return addToBST(numbers, 0, numbers.size() - 1);
}

//test
//    vector<int> numbers{12, 43, 2, 5, 34, 33};
//    
//    sort(numbers.begin(), numbers.end());
//    
//    TreeNode* newRoot = createMinimalBST(numbers);
//    
//    cout << endl;

#endif /* Tree_8_h */
