//
//  Tree_7.h
//  Test2019
//
//  Created by Denys Risukhin on 2/7/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef Tree_7_h
#define Tree_7_h

struct TreeNode
{
    TreeNode(): m_leftPtr(nullptr), m_rightPtr(nullptr), m_data(0) {}
    TreeNode(int data): m_leftPtr(nullptr), m_rightPtr(nullptr), m_data(data) {}
    
    TreeNode* m_leftPtr = nullptr;
    TreeNode* m_rightPtr = nullptr;
    int m_data;
};


/* A utility function to check
 whether trees with roots as root1 and
 root2 are identical or not */
bool isIdentical(TreeNode* root1, TreeNode* root2)
{
    /* base cases */
    if (root1 == NULL && root2 == NULL)
        return true;
    
    if (root1 == NULL || root2 == NULL)
        return false;
    
    /* Check if the data of both roots is
     same and data of left and right
     subtrees are also same */
    return (root1->m_data == root2->m_data &&
            isIdentical(root1->m_leftPtr, root2->m_leftPtr) &&
            isIdentical(root1->m_rightPtr, root2->m_rightPtr) );
}

/* This function returns true if S
 is a subtree of T, otherwise false */
bool isSubtree(TreeNode* globalTree, TreeNode* subTree)
{
    /* base cases */
    if (subTree == nullptr)
        return true;
    
    if (globalTree == nullptr)
        return false;
    
    /* Check the tree with root as current node */
    if (isIdentical(globalTree, subTree))
        return true;
    
    /* If the tree with root as current
     node doesn't match then try left
     and right subtrees one by one */
    return isSubtree(globalTree->m_leftPtr, subTree) || isSubtree(globalTree->m_rightPtr, subTree);
}

/* Helper function that allocates
 a new node with the given data
 and NULL left and right pointers. */
TreeNode* newNode(int data)
{
    TreeNode* Node = new TreeNode;
    Node->m_data = data;
    Node->m_leftPtr = NULL;
    Node->m_rightPtr = NULL;
    return(Node);
}

// test

// globalTree
//          26
//     10       3
//  4     6       3
//   30
//
//

//    TreeNode* globalTree = newNode(26);
//    globalTree->m_rightPtr = newNode(3);
//    globalTree->m_rightPtr->m_rightPtr = newNode(3);
//    globalTree->m_leftPtr = newNode(10);
//    globalTree->m_leftPtr->m_leftPtr = newNode(4);
//    globalTree->m_leftPtr->m_leftPtr->m_rightPtr = newNode(30);
//    globalTree->m_leftPtr->m_rightPtr = newNode(6);
//
//    // subTree
//    //     10
//    //  4     6
//    //   30
//
//    TreeNode* subTree = newNode(10);
//    subTree->m_rightPtr = newNode(6);
//    subTree->m_leftPtr = newNode(4);
//    subTree->m_leftPtr->m_rightPtr = newNode(30);
//
//    if (isSubtree(globalTree, subTree))
//        cout << "Tree 2 is subtree of Tree 1";
//    else
//        cout << "Tree 2 is not a subtree of Tree 1";
//
//    // need to release memory
//
//    cout << endl;
//


#endif /* Tree_7_h */
