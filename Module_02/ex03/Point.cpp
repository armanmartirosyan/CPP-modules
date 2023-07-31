#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const Point& obj) : _x(obj._x), _y(obj._y) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point& Point::operator=(const Point& obj) {
	(Fixed)this->_x = obj.getFixedX();
	(Fixed)this->_y = obj.getFixedY();
	return (*this);
}

Point::~Point(void) {}

Fixed	Point::getFixedX(void) const {
	return (this->_x);
}

Fixed	Point::getFixedY(void) const {
	return (this->_y);
}