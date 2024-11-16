//
//  Tree_1_c.h
//  Test2019
//
//  Created by Risukhin Denys on 1/19/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Tree_1_c_h
#define Tree_1_c_h

template <class T>
struct Node
{
    T m_data;
    Node* m_brother = nullptr;
    Node* m_son = nullptr;
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
        
        return getNodeAmountFromLevel(node->m_son, level - 1) + (level == 1) + getNodeAmountFromLevel(node->m_brother, level); // WTF
    }
    
    int getHeight(Node<T>* node)
    {
        if (!node)
        {
            return 0;
        }
        
        auto max = 0;
        
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
               {
                   rootNode = new Node<T>(rootNode); // ?
               }
               else if (data < rootNode->m_data)
               {
                   add(rootNode->m_son, data);
               }
               else
               {
                   add(rootNode->m_brother, data);
               }
           }
       };

#endif /* Tree_1_c_h */
