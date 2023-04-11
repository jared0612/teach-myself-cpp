#ifndef _POINT_H_
#define _POINT_H_

class Line;
class Point {
public :
    Point();
    Point(float x, float y);
    friend class Line; 
private:
    float _x, _y;
};

#endif
