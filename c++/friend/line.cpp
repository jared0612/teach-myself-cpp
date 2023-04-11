#include "line.h"
#include<math.h>

Line::Line(const Point& p1, const Point& p2) {
    this->_p1 = p1;
    this->_p2 = p2;
}
float Line::getDistance() {
    return sqrt((_p1._x - _p2._x)*(_p1._x - _p2._x)+(_p1._y - _p2._y)*(_p1._y - _p2._y));
}