#include<iostream>
using namespace std;


class Point{
private:
    float _x, _y;
public:
    Point() : _x(0), _y(0){}
    Point(float x, float y):_x(x), _y(y){}
    void print(int n);
    void print(float n);

    //友元函数可以访问对象的属性和方法
    friend void print(const Point&, int);
    friend void print(const Point&, double);
    

};

void Point::print(int n) {
    cout << "x = " << (int )_x ;
    cout << "   y = " << (int )_y << endl;
}

void Point::print(float n) {
    cout << "x = " << _x ;
    cout << "   y = " << _y << endl;
}

void print(const Point& p, int n) {
    cout << "x = " << (int)p._x ;
    cout << "   y = " << (int)p._y << endl;
}

void print(const Point& p, double n) {
    cout << "x = " << p._x ;
    cout << "   y = " << p._y << endl;
}

int main() {
    Point p1(1.0, 2.0);
    Point p2(2.3, 5.6);
    p1.print(2);
    p2.print(2.0f);

    print(p1, 2);
    print(p2, 2.0);

    return 0;
}