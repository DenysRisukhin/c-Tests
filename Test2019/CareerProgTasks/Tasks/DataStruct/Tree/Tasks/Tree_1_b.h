//
//  Tree_1_b.h
//  Test2019
//
//  Created by Denys Risukhin on 2/6/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef Tree_1_b_h
#define Tree_1_b_h

#include <iostream>
#include <queue>

#pragma mark - search binary tree

template <class T>
class binary_search_tree: public binary_tree<T>
{
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
#endif /* Tree_1_b_h */
