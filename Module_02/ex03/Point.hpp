#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		Point(void);
		Point(const Point&);
		Point(const float, const float);
		Point& operator=(const Point&);
		~Point(void);

		// Functions
		Fixed	getFixedX(void) const;
		Fixed	getFixedY(void) const;
		
	private:
		Fixed const _x;
		Fixed const _y;

};

bool bsp( Point const, Point const, Point const, Point const );

#endif