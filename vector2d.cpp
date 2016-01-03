#include "vector2d.h"


Vector2D operator+(const Vector2D& other) const {
    return Vector2D(_x + other._x, _y + other._y);
}


Vector2D& operator+=const Vector2D& other) {
    _x += other._x;
    _y += other._y;
    return *this;
}
