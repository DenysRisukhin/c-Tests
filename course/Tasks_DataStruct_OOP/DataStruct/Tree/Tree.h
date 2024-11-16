//
//  Header.h
//  Test2019
//
//  Created by Denys Risukhin on 7/22/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <queue>

template <class T>
struct Node
{
    T m_data;

    Node<T>* m_left = nullptr;
    Node<T>* m_right = nullptr;

    Node<T>* m_nextPtr = nullptr;
    
    Node<T>* m_brother = nullptr;
    Node<T>* m_son = nullptr;
};

#pragma mark - tree

template<class T>
class tree
{
public:
    tree(): m_rootNode(nullptr)
    {
        // do nothing
    }
    ~tree() { destroy(m_rootNode); }
    
    int getHeight() { return getHeight(m_rootNode); }
    int getNodeAmountFromLevel(int level) { return getNodeAmountFromLevel(m_rootNode, level); }
    
    void add(const T& data) { add(m_rootNode, data); }

protected:
    Node<T>* m_rootNode = nullptr;
    
private:
    void destroy(Node<T>* node)
    {
        destroy(node->m_son);
        destroy(node->m_brother);
        delete node;
    }
    
    int getNodeAmountFromLevel(Node<T>* node, int level)
    {
        if (!node || level < 0)
        {
            return 0;
        }
        
        return getNodeAmountFromLevel(node->m_son, level - 1) + (level == 1) + getNodeAmountFromLevel(node->m_brother, level);
    }
    
    int getHeight(Node<T>* node)
    {
        if (!node)
        {
            return 0;
        }
        
        int max = 0;
        
        for (auto curNode = node->m_son; curNode ; curNode = curNode->m_brother)
        {
            auto curHeight = getHeight(curNode);
            if (curHeight > max)
            {
                max = curHeight;
            }
        }

        return max + 1;
    }

    void add(Node<T>*& rootNode, const T& data)
    {
        if (!rootNode)
            rootNode = new Node<T>(rootNode);
        else if (data < rootNode->m_data)
            add(rootNode->m_son, data);
        else
            add(rootNode->m_brother, data);
    }
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
        if (tree)
        {
            copy(m_rootNode, tree.m_rootNode);
        }
        else
        {
            m_rootNode = nullptr;
        }
    }
    
    binary_tree(binary_tree<T>&& tree) noexcept
    {
        if (tree)
        {
            copy(m_rootNode, tree.m_rootNode);
        }
        else
        {
            m_rootNode = nullptr;
        }
        
        tree.m_rootNode = nullptr;
    }
    
    binary_tree& operator=(const binary_tree<T>& tree)
    {
        if (this != tree)
        {
            if(m_rootNode)
            {
                destroy(m_rootNode);
            }
            else if (!tree.m_rootNode)
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
        
    }
    
    ~binary_tree() { destroy(m_rootNode); }
    
    bool empty() const noexcept { return m_rootNode == nullptr; }
    
    void inorder() const noexcept { inorder(m_rootNode); }
    void preorder() const noexcept { preorder(m_rootNode); }
    void postorder() const noexcept { postorder(m_rootNode); }

// special stuff
    int getNodeCount() const noexcept { getNodeCount(m_rootNode); }
    int getHeight() const noexcept { getHeight(m_rootNode); }
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
        if (rootNode) {
            inorder(rootNode->m_left);
            inorder(m_rootNode->m_right);
            std::cout << rootNode->m_data << std::endl;
        }
    }
    
    void copy(Node<T>*& lNode, Node<T>* rNode) noexcept {
        if (rNode == nullptr) {
            lNode = nullptr;
        } else {
            lNode = new Node<T>();
            lNode->m_data = rNode->m_data;
            lNode->m_left = rNode->m_left;
            lNode->m_right = rNode->m_right;
        }
    }
        
    void destroy(Node<T>*& root) noexcept {
        if (root) {
            destroy(root->m_left);
            destroy(root->m_right);
            delete root;
            root = nullptr;
        }
    }
            
// special stuff
            
    int getNodeCount(Node<T>* rootNode) const noexcept
    {
        if (rootNode) {
            if (rootNode->m_left == nullptr && rootNode->m_right == nullptr) {
                return 1;
            }
            
            int left = 0;
            int right = 0;
            
            if (rootNode->m_left) {
                left = getNodeCount(rootNode->m_left);
            } else {
                left = 0;
            }
            
            if (rootNode->m_right) {
                right =  getNodeCount(rootNode->m_right);
            } else {
                right = 0;
            }
            
            return left + right + 1;
        } else {
            return 0;
        }
    }
            
    int getHeight(Node<T>* rootNode) const noexcept
    {
        if (rootNode) {
            return 1 + max(getHeight(rootNode->m_left), getHeight(rootNode->m_right));
        } else {
            return 0;
        }
    }
            
    int max(int l, int r)
    {
        if (l >= r) {
            return l;
        } else {
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
        
        if (rootNode == nullptr) {
            return;
        }
        
        queue.push(rootNode);
        cnt = 1;
        cntNext = 0;
        
        while(!queue.empty()) {
            curNode = queue.front();
            queue.pop();
            
            if (curNode->m_left) {
                queue,push(curNode->m_left);
                cntNext++;
            }
            
            if (curNode->m_right) {
                queue,push(curNode->m_right);
                cntNext++;
            }
            
            if (prevNode) {
                prevNode->m_next = prevNode;
            }
            
            prevNode = curNode;
            cnt--;
            if (cnt == 0) {
                cnt = cntNext;
                cntNext = 0;
                prevNode = nullptr;
            }
        }
    }
            
};

#pragma mark - search binary tree

template <class T>
class binary_search_tree: public binary_tree<T> {
public:
    bool search(const T& data) const
    {
        Node<T>* curNode = nullptr;
        bool isFound = false;
        
        if (!this->m_rootNode) {
            return false;
        } else {
            curNode = this->m_rootNode;
            while(curNode && isFound) {
                if (curNode->m_data == data) {
                    isFound = true;
                } else if (curNode->m_data > data) {
                    curNode = curNode->m_left;
                } else {
                    curNode = curNode->m_right;
                }
            }
        }
        return isFound;
    }
    
    // created by ITBoy
    // big O : O(n)
    // input : bool breadthFirstSearch(Node<T> rootNode, const T& data)
    // output: bool value

    bool breadthFirstSearch(Node<T> rootNode, const T& data) {
        if (!rootNode) {
            return false;
        }
        
        std::queue<Node<T>> queueNodes;
        queueNodes.push(rootNode);
        
        while (!queueNodes.empty()) {
            auto tempNode = queueNodes.front();
            queueNodes.pop();
            
            if (tempNode->m_data == data) {
                return true;
            } else {
                if (tempNode->m_left) {
                    queueNodes.push(tempNode->m_left);
                } else  if (tempNode->m_right) {
                    queueNodes.push(tempNode->m_right);
                }
            }
        }
        return false;
    }

    void insert(const T& data)
    {
        Node<T>* curNode = nullptr;
        Node<T>* trailNode = nullptr;
        
        Node<T>* newNode = new Node<T>();
        newNode->m_data = data;
        newNode->m_left = nullptr;
        newNode->m_right = nullptr;
        
        if (!this->m_rootNode)
        {
            this->m_rootNode = newNode;
        }
        else
        {
            curNode = this->m_rootNode;
            
            while(curNode)
            {
                trailNode = curNode;
                
                if (curNode->m_data == data) {
                    std::cout << "data has already added to tree" << std::endl;
                    return;
                }
                else if (curNode->m_data > data)
                {
                    curNode = curNode->m_left;
                }
                else
                {
                    curNode = curNode->m_right;
                }
            }
            
            if (trailNode->m_data > data)
            {
                trailNode->m_left = newNode;
            }
            else
            {
                trailNode->m_right = newNode;
            }
        }
    }

    void remove(const T& data)
    {
        Node<T>* curNode = nullptr;
        Node<T>* trailNode = nullptr;
        bool isFound = false;
        
        if (!this->m_rootNode) {
            return;
        }
        else
        {
            curNode = this->m_rootNode;
            trailNode = this->m_rootNode;
            
            while(curNode && !isFound)
            {
                if (curNode->m_data == data)
                {
                    isFound = true;
                }
                else
                {
                    trailNode = curNode;
                    if (curNode->m_data > data)
                    {
                        curNode = curNode->m_left;
                    }
                    else
                    {
                        curNode = curNode->m_right;
                    }
                }
            }
            
            if (!curNode)
            {
                std::cout << "node with data hasn't fined in tree" << std::endl;
            }
            else if (isFound)
            {
                if (curNode == this->m_rootNode)
                {
                    removeNode(curNode);
                }
                else if (trailNode->m_data > data)
                {
                    removeNode(trailNode->m_left);
                }
                else
                {
                    removeNode(trailNode->m_right);
                }
            }
            
        }
    }

private:
    void removeNode(Node<T>*& node)
    {
        Node<T>* curNode = nullptr;
        Node<T>* trailNode = nullptr;
        Node<T>* tempNode = nullptr;
        
        if (!node)
        {
            return;
        }
        else if (!node->m_left && !node->m_right)
        {
            tempNode = node;
            node = nullptr;
            delete tempNode;
        }
        else if (!node->m_left)
        {
            tempNode = node;
            node = node->m_right;
            delete tempNode;
        }
        else if (!node->m_right)
        {
            tempNode = node;
            node = node->m_left;
            delete tempNode;
        }
        else
        {
            curNode = node->m_left;
            
            while(curNode->m_right)
            {
                trailNode = curNode;
                curNode = curNode->m_right;
            }
            
            node->m_data = curNode->m_data;
            
            if (!trailNode)
            {
                node->m_left = curNode->m_left;
            }
            else
            {
                trailNode->m_right = curNode->m_left;
            }

            // cheks this place
            delete curNode;
        }
    }
};

#endif /* Header_h */
