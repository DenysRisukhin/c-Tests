//
//  auto_ptr.h
//  Test2019
//
//  Created by Denys Risukhin on 6/27/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef auto_ptr_h
#define auto_ptr_h

template <class T>
struct auto_ptr_ref
{
    T* m_ptr = nullptr;
};

template<class T>
class auto_ptr {
public:
    
    // c-tor
    explicit auto_ptr(T* ptr = nullptr) noexcept : m_ptr(ptr) {
        // do nothing
    }
    
    // cpy c-tor
    auto_ptr(const auto_ptr& ptr) noexcept { m_ptr(ptr.release()); }
    
    template<class U>
    auto_ptr(auto_ptr<U>& ptr) throw() : m_ptr(ptr.release()) {}
    
    auto_ptr(auto_ptr&& ptr) noexcept: m_ptr(std::exchange(ptr.m_obj, nullptr)) {
        // do nothing
    }
    
    // d-tor
    ~auto_ptr() noexcept { delete m_ptr; }
    
    // release
    T* release() noexcept {
        T* tmp(m_ptr);
        m_ptr = nullptr;
        return tmp;
    }
    
    // reinitialization
    void reset(T* ptr = nullptr) noexcept {
        if (m_ptr != ptr) {
            delete m_ptr;
        }
        m_ptr = ptr;
    }
    
    // ***
    // overloading section
    // ***
    
    //assignment operators
    auto_ptr& operator=(auto_ptr& ptr) noexcept {
        reset(ptr.release());
        return *this;
    }
    
    template<class U> auto_ptr& operator=(auto_ptr<U>& ptr) noexcept {
        reset(ptr.release());
        return *this;
    }
    
    // Селектор. Позволяет обращаться к данным типа T посредством "стрелочки"
    T* operator->() const noexcept { return m_ptr; }
    // access by pointer
    T* get() const noexcept { return m_ptr; }
    
    // разыменовать указатель и получить ссылку на объект, который он хранит
    T& operator*() noexcept { return *m_ptr; }
    
    
    operator bool() const { return m_ptr != nullptr; }
    bool operator==(T* rhs) const { return m_ptr == rhs; }
    bool operator!=(T* rhs) const { return m_ptr != rhs; }
    std::ptrdiff_t operator-(auto_ptr<T> ptr) { return m_ptr - ptr; }
    std::ptrdiff_t operator-(void *ptr) { return m_ptr - ptr; }
    
    // ***
    // auto_ptr_ref section
    // ***
    
    auto_ptr& operator=(auto_ptr_ref<T> ptr) throw() {
        reset(ptr.m_ptr);
        return *this;
        
    }
    
    auto_ptr(auto_ptr_ref<T> ptr) noexcept : m_ptr(ptr.m_ptr) {}
    
    template<class U>
    operator auto_ptr_ref<U>() noexcept {
        auto_ptr_ref<U> t;
        t.m_ptr = release();
        return t;
    }
    
    template<class U>
    operator auto_ptr<U>() noexcept { return auto_ptr<U>(release()); }
    
private:
    T* m_ptr = nullptr;
};

// test data

#pragma mark - cycle link
//
//struct B;
//
//struct A {
//    A() { std::cout << "A()" << std::endl; }
//    ~A() { std::cout << "~A()" << std::endl; }
//
//    int m_value;
//    std::shared_ptr<B> b;
//};
//
//struct B {
//
//    B() { std::cout << "B()" << std::endl; }
//    ~B() { std::cout << "~B()" << std::endl; }
//
//    int m_value;
//    std::weak_ptr<A> a;
//};
//
#pragma mark - test code
//
//class Point {
//public:
//    Point(double x, double y): m_x(x), m_y(y) {
//        m_p1 = nullptr;
//        m_p2 = nullptr;
//    }
//
//    Point(double x, double y, shared_ptr<Point> p1, shared_ptr<Point> p2): m_x(x), m_y(y) {
//        m_p1 = p1;
//        m_p2 = p2;
//    }
//
//    void setX(double x)  {m_x = x;}
//    void setY(double y)  {m_y = y;}
//    void setP1(shared_ptr<Point> p1) {m_p1 = p1;}
//    void setP2(shared_ptr<Point> p2) {m_p2 = p2;}
//
//    double getX(){ return m_x; }
//    double getY(){ return m_y; }
//
//    void print() {
//        std::cout << "x= " << m_x << " y= " << m_y << '\n';
//        std::cout << "p1" << '\n';
//
//        if (m_p1 != nullptr) {
//            m_p1->print();
//        }
//
//        std::cout << "p2" << '\n';
//
//        if (m_p2 != nullptr) {
//            m_p2->print();
//        }
//
//        std::cout << '\n';
//    }
//
//private:
//    double m_x = 0;
//    double m_y = 0;
//    shared_ptr<Point> m_p1 = nullptr;
//    shared_ptr<Point> m_p2 = nullptr;;
//};
//
#pragma mark - list of pointers
//
//class PointList {
//public:
//    shared_ptr<Point>& operator[] (int idx) {
//        return points[idx];
//    }
//
//    void erase(unsigned int idx) {
//        points.erase(points.begin() += idx);
//    }
//
//    void push_back(shared_ptr<Point> ptr) {
//        points.push_back(ptr);
//    }
//
//    void printPoints() {
//        std::cout << "List of points" << '\n';
//        for (unsigned int i = 0; i < points.size();  i++) {
//            points[i]->print();
//        }
//    }
//
//private:
//    std::vector< shared_ptr<Point> > points;
//};
//
//
//void printNum(int i) {
//    std::cout << i << std::endl;
//}
//
//struct Fox {
//    Fox(int num) : m_num(num) {}
//
//    void print(int i) const {
//        std::cout << i << std::endl;
//    }
//    int m_num;
//};

//*******
//*SmartPtr main test*
//*******

//std:: cout << "\n\n*SmartPtr*\n";
//shared_ptr<Point> p0(new Point(0,0));
//p0->print();
//shared_ptr<Point> p1(new Point(10,10));
//p1->print();
//shared_ptr<Point> p2(new Point(20,20));
//p2->print();
//shared_ptr<Point> p3(new Point(30,30));
//p3->print();
//
//shared_ptr<Point> pa(p3);
//p0->setP1(p2);
//p0->setP2(p3);
//p0->print();
//p0 = p1;
//p0->print();
//p0->print();
//
//PointList pl1;
//pl1.push_back(p0);
//pl1.push_back(p1);
//
//PointList pl2;
//pl2.push_back(p2);
//pl2.push_back(p3);
//pl1.erase(0);
//pl1.printPoints();
//pl2.printPoints();

#endif /* auto_ptr_h */
