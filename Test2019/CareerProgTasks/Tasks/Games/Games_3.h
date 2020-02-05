//
//  Games_3.h
//  Test2019
//
//  Created by Denys Risukhin on 2/5/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef Games_3_h
#define Games_3_h

#pragma mark - 16.3 Point
class Point
{
public:
    Point(double x, double y)
    : m_x(x), m_y(y) {}
    
    void setLocation(double x, double y)
    {
        m_x = x;
        m_y = y;
    }
    
    void setX(double x) { m_x = x; }
    void setY(double y) { m_y = y; }
    
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    
private:
    double m_x;
    double m_y;
};

#pragma mark - 16.3 Line

class Line
{
public:
    Line(Point start, Point end)
    {
        auto deltaY = end.getY() - start.getY();
        auto deltaX = end.getX() - start.getX();
        
        m_slope = deltaY / deltaX;
        m_yIntercept = end.getY() - m_slope * end.getX();
    }
    
    double getSlope() const { return m_slope; }
    double getYIntercept() const { return m_yIntercept; }
    
private:
    double m_slope;
    double m_yIntercept;
};

#pragma mark - 16.3 extra stuff

void swap(Point one, Point two)
{
    auto x = one.getX();
    auto y = one.getY();
    
    one.setLocation(two.getX(), two.getY());
    two.setLocation(x, y);
}

bool isBetween(double start, double middle, double end)
{
    if (start > end)
    {
        return end <= middle && middle <= start;
    }
    
    return start <= middle && middle <= end;
}

bool isBetween(Point start, Point middle, Point end)
{
    return isBetween(start.getX(), middle.getX(), end.getX()) && isBetween(start.getY(), middle.getY(), end.getY());
}

#pragma mark - 16.3 logic

Point intersection(Point start1, Point end1, Point start2, Point end2)
{
    if (start1.getX() > end1.getX())
    {
        swap(start1, end1);
    }
    
    if (start2.getX() > end2.getX())
    {
        swap(start2, end2);
    }
    
    if (start1.getX() > start2.getX())
    {
        swap(start1, start2);
        swap(end1, end2);
    }
    
    Line line1(start1, end1);
    Line line2(start2, end2);
    
    if (line1.getSlope() == line2.getSlope())
    {
        if (line1.getYIntercept() == line2.getYIntercept() && isBetween(start1, start2, end2))
        {
            return start2;
        }
        
        return Point(-1, -1);
    }
    
    double x = (line2.getYIntercept() - line1.getYIntercept()) / (line1.getSlope() - line2.getSlope());
    double y = x * line1.getSlope() + line1.getYIntercept();
    Point intersection = Point(x, y);
    
    if (isBetween(start1, intersection, end1) && isBetween(start2, intersection, end2))
    {
        return intersection;
    }
    
    return Point(-1, -1);
}


#endif /* Games_3_h */
