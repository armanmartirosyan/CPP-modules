#include <cmath>
#include "Point.hpp"

static Fixed module(const Fixed num)
{
    if (num < 0)
        return (num * -1);
    return (num);
}

static Fixed getTriangleArea(Point const a, Point const b, Point const c) {
	return ((a.getFixedX() * (b.getFixedY() - c.getFixedY()) + 
			(b.getFixedX() * (c.getFixedY() - a.getFixedY())) + 
			(c.getFixedX() * (a.getFixedY() - b.getFixedY()))) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	mainTriangle = module (getTriangleArea(a, b, c));
	Fixed	p1Triangle   = module (getTriangleArea(point, a, b));
	Fixed	p2Triangle   = module (getTriangleArea(point, b, c));
	Fixed	p3Triangle   = module (getTriangleArea(point, c, a));

	// std::cout << "Main: " << mainTriangle.toFloat() << std::endl;
	// std::cout << "Sum: " << p1Triangle + p2Triangle + p3Triangle << std::endl;

	return (mainTriangle == (p1Triangle + p2Triangle + p3Triangle));
}