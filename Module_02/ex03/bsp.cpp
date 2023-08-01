#include "Point.hpp"

Fixed crossProduct(Point p1, Point p2, Point p3) {
    return (p2.getFixedX() - p1.getFixedX())
			* (p3.getFixedY() - p1.getFixedY())
			- (p2.getFixedY() - p1.getFixedY())
			* (p3.getFixedX() - p1.getFixedX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed cross1(crossProduct(a, b, point));
    Fixed cross2(crossProduct(b, c, point));
    Fixed cross3(crossProduct(c, a, point));

    if ((cross1 > 0 && cross2 > 0 && cross3 > 0) || 
        (cross1 < 0 && cross2 < 0 && cross3 < 0))
        return (true);
    return (false);
}