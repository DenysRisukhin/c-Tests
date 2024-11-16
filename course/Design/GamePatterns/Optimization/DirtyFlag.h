//
//  DirtyFlag.h
//  Test2019
//
//  Created by Risukhin Denys on 2/11/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef DirtyFlag_h
#define DirtyFlag_h

//Набор первичных данных изменяется со временем. Набор вторичных данных вычисляется на основе первичных с помощью ресурсоемкого процесса. "Грязный" флаг отслеживает рассинхронизацию вторичных данных с
//первичными. Он устанавливается когда первичные данные изменяются. Если флаг установлен когда нам понадобились вторичные данные, они вычисляются и
//флаг снимается. В противном случае используются уже вычисленные
//вторичные данные.

// usage
//когда у вас есть реальная проблема с производительностью, ради решения которой имеет смысл заплатить увеличением сложности кода.

//Грязный флаг применяется к двум типам работ: вычислениям и синхронизации. В обеих случаях процесс перехода от первичных данных к вторичным требует либо
//времени, либо дополнительных затрат.

class Transform {
public:
    static Transform origin();
    Transform combine(Transform& other);
    
};

#pragma mark - GraphNode

class GraphNode
{
public:
    GraphNode(Mesh* mesh)
        : mesh_(mesh)
        , local_(Transform::origin())
    {}
    
    void setTransform(Transform local)
    {
        local_ = local;
        dirty_ = true;
    }
    
    void GraphNode::render(Transform parentWorld, bool dirty)
    {
        dirty |= dirty_;
        if (dirty)
        {
            world_ = local_.combine(parentWorld);
            dirty_ = false;
        }
        
        if (mesh_)
            renderMesh(mesh_, world_);
        
        for (int i = 0; i < numChildren_; i++)
        {
            children_[i]->render(world_, dirty);
        }
    }

private:
    Transform world_;
    bool dirty_;

    Transform local_;
    Mesh* mesh_;

    GraphNode* children_[MAX_CHILDREN];
    int numChildren_;
};

//GraphNode* graph_ = new GraphNode(NULL); // Добавление дочернего узла к корневому узлу графа...

void renderMesh(Mesh* mesh, Transform transform)
{
    
}



//Архитектурные решения

    //Когда очищается грязный флаг?
        - Когда нам потребуется результат:
        - В жестко определенных контрольных точках
        - В фоне

#endif /* DirtyFlag_h */
