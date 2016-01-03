#ifndef VECTOR2D_H
#define VECTOR2D_H


#include<math.h>


class Vector2D {
    private:
        float _x;
        float _y;

    public:
        Vector2D(float x, float y): _x(x), _y(y) {}

        float get_x() {return _x;}

        float get_y() {return _y;}

        float set_x(float x) {_x = x;}

        float set_y(float y) {_y = y;}

        float length() {return sqrt(_x*_x + _y*_y);}
};

#endif
