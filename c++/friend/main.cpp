#include<iostream>
#include"line.h"

using namespace std;

int main( ) {
    Point p1(0,1),p2(1,5);
    Line line(p1,p2);
    
    float len = line.getDistance();
    cout << len << endl;
    return 0;
}