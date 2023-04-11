#ifndef _LINE_H_
#define _LINE_H_
#include "point.h"

class Line{

public:
    Line(const Point &, const Point &);
    float getDistance();
private:
    Point _p1, _p2;
};

#endif