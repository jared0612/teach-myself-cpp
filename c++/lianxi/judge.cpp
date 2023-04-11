/*************************************************************************
	> File Name: judge.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Jul 2022 02:31:59 PM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;

class Point {
    friend double Distance(const Point &p1, const Point &p2) {
        double px = p1.x__ - p2.x__;
        double py = p1.y__ - p2.y__;
        return sqrt(px * px + py * py);
    }
public:
    Point(int x, int y) : x__(x), y__(y) {}
private:
    int x__;
    int y__;
};

int main() {
    Point p1(3, 4);
    Point p2(4, 5);
   
    cout << Distance(p1, p2) << endl;

    return 0;
}
