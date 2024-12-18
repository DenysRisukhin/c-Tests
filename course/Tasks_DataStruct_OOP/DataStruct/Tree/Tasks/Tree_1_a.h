//
//  Tree_1_a.h
//  Test2019
//
//  Created by Risukhin Denys on 1/19/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Tree_1_a_h
#define Tree_1_a_h

#include <iostream>
#include <queue>

template <class T>
struct Node
{
    T m_data;
    Node* m_left = nullptr;
    Node* m_right = nullptr;
};

#pragma mark - bynary tree

template<class T>
class binary_tree
{
public:
    
    binary_tree() noexcept: m_rootNode(nullptr)
    {
        // do nothing
    }
    
    binary_tree(const binary_tree<T>& tree) noexcept
    {
        if (!tree)
        {
            m_rootNode = nullptr;
            return;
        }

        copy(m_rootNode, tree.m_rootNode);
    }
    
    binary_tree(binary_tree<T>&& tree) noexcept
    {
        if (!tree)
        {
            m_rootNode = nullptr;
            return;
        }

        copy(m_rootNode, tree.m_rootNode);
        
        tree = nullptr; // ? i think it's ok but needs to check
        // or
        // tree.m_rootNode = nullptr;
    }
    
    binary_tree& operator=(const binary_tree<T>& tree)
    {
        if (this != tree)
        {
            // maybe needs fix
//            if(m_rootNode)
//            {
//                destroy(m_rootNode);
//            }
//            else if (!tree.m_rootNode)
//            {
//                m_rootNode = nullptr;
//            }
//            else
//            {
//                copy(m_rootNode, tree.m_rootNode);
//            }
            
        // fix: firstly we must remove current tree
            if(m_rootNode)
            {
                destroy(m_rootNode);
            }
            
            if (!tree.m_rootNode)
            {
                m_rootNode = nullptr;
            }
            else
            {
                copy(m_rootNode, tree.m_rootNode);
            }
        }
        
        return *this;
    }
    
    binary_tree& operator=(binary_tree<T>&& tree)
    {
        // add logic
    }
    
    ~binary_tree() { destroy(m_rootNode); }
    
    bool empty() const noexcept { return m_rootNode == nullptr; }
    
    void inorder() const noexcept { inorder(m_rootNode); }
    void preorder() const noexcept { preorder(m_rootNode); }
    void postorder() const noexcept { postorder(m_rootNode); }
    
    // special stuff
    
    int getNodeCount() const noexcept { getNodeCount(m_rootNode); }
    int getHeight() const noexcept { getHeight(m_rootNode); }
    
    
    // why do i need this method?
    void linkLevelN() const noexcept { getHeight(m_rootNode); }
    
protected:
    Node<T>* m_rootNode = nullptr;
    
private:
    void inorder(Node<T>* rootNode) const noexcept
    {
        if (rootNode) {
            inorder(rootNode->m_left);
            std::cout << rootNode->m_data << std::endl;
            inorder(m_rootNode->m_right);
        }
    }
    
    void preorder(Node<T>* rootNode) const noexcept
    {
        if (rootNode) {
            std::cout << rootNode->m_data << std::endl;
            inorder(rootNode->m_left);
            inorder(m_rootNode->m_right);
        }
    }
    
    void postorder(Node<T>* rootNode) const noexcept
    {
        if (rootNode)
        {
            inorder(rootNode->m_left);
            inorder(m_rootNode->m_right);
            std::cout << rootNode->m_data << std::endl;
        }
    }
    
    void copy(Node<T>*& rootNode, Node<T>* otherNode) noexcept
    {
        if (!otherNode)
        {
            rootNode = nullptr;
        }
        else
        {
            rootNode = new Node<T>();
            rootNode->m_data = otherNode->m_data;
            rootNode->m_left = otherNode->m_left;
            rootNode->m_right = otherNode->m_right;
        }
    }
    
    void destroy(Node<T>*& root) noexcept
    {
        if (root)
        {
            destroy(root->m_left);
            destroy(root->m_right);
            delete root;
            root = nullptr;
        }
    }
    
#pragma mark - special stuff
    
    int getNodeAmounts(Node<T>* rootNode) const noexcept
    {
        if (rootNode)
        {
            if (rootNode->m_left == nullptr && rootNode->m_right == nullptr)
            {
                return 1;
            }
            
            int left = 0;
            int right = 0;
            
            if (rootNode->m_left)
            {
                left = getNodeCount(rootNode->m_left);
            }
            else
            {
                left = 0;
            }
            
            if (rootNode->m_right)
            {
                right = getNodeCount(rootNode->m_right);
            }
            else
            {
                right = 0;
            }
            
            return left + right + 1;
        }
       
        return 0;
    }
    
    int getHeight(Node<T>* rootNode) const noexcept
    {
        if (rootNode)
        {
            return 1 + max(getHeight(rootNode->m_left), getHeight(rootNode->m_right));
        }
        else
        {
            return 0;
        }
    }
    
    int max(int l, int r)
    {
        if (l >= r)
        {
            return l;
        }
        else
        {
            return r;
        }
    }
    
    void linkLevelN(Node<T>* rootNode) const noexcept
    {
        std::queue<Node<T>*> queue;
        Node<T>* prevNode = nullptr;
        Node<T>* curNode = nullptr;
        int cnt;
        int cntNext;
        
        if (rootNode == nullptr)
        {
            return;
        }
        
        queue.push(rootNode);
        cnt = 1;
        cntNext = 0;
        
        while(!queue.empty())
        {
            curNode = queue.front();
            queue.pop();
            
            if (curNode->m_left)
            {
                queue,push(curNode->m_left);
                cntNext++;
            }
            
            if (curNode->m_right)
            {
                queue,push(curNode->m_right);
                cntNext++;
            }
            
            if (prevNode)
            {
                prevNode->m_next = prevNode;
            }
            
            prevNode = curNode;
            cnt--;
            
            if (cnt == 0)
            {
                cnt = cntNext;
                cntNext = 0;
                prevNode = nullptr;
            }
        }
    }
};

#endif /* Tree_1_a_h */
