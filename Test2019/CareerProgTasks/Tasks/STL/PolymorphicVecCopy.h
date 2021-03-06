//
//  Header.h
//  Test2019
//
//  Created by Denys Risukhin on 12/7/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef PolymorphicVecCopy_h
#define PolymorphicVecCopy_h

#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0;
    virtual Shape* clone() = 0;
    virtual ~Shape() {};
};

class Circle: public Shape
{
public:
    Circle(): m_radius(0.f) {};
    void draw() { cout << "circle" << endl; };
    Shape* clone() { return new Circle(); };
    
private:
    float m_radius;
};

class Rect: public Shape
{
public:
    Rect(): m_x(0.f), m_y(0.f) {};
    void draw() { cout << "Rect" << endl; };
    Shape* clone() { return new Rect(); };
    
private:
    float m_x;
    float m_y;
};

//const vector<Shape*>& getVectorCopy(const vector<Shape*>& tempShapes) // error because &
//libc++abi.dylib: terminating with uncaught exception of type std::length_error: vector

const vector<Shape*> getVectorCopy(const vector<Shape*>& tempShapes)
{
    //vector<Shape*> shapes = tempShapes;// wrong copy: because shapes will get pointers to the same scope that vec tempShapes has.
    
    
    vector<Shape*> shapes(tempShapes.size());
    //shapes.resize(tempShapes.size()) // it's ok init too
    
    if (tempShapes.size() == 0)
    {
        return shapes;
    }
    
    
    for (int i = 0; i < shapes.size(); i++)
    {
        shapes[i] = tempShapes[i]->clone();
    }
    
    return shapes;
}

//int main(int argc, const char * argv[])
//{
//    vector<Shape*> shapes;
//    shapes.push_back(new Circle);
//    shapes.push_back(new Rect);
//    
//    for (Shape* shape: shapes)
//    {
//        shape->draw();
//    }
//
//    auto copyShapesVec = getVectorCopy(shapes);
//
//    for (Shape* shape: shapes)
//    {
//        delete shape;
//    }
//
//    for (Shape* shape: copyShapesVec)
//    {
//        shape->draw();
//    }
//
//    return 0;
//}


#endif /* Header_h */
