#include "Point.hpp"

int main( void ) 
{
     if (bsp(Point(16, 7), Point(57, 65.45), Point(34.34, 3.14159265), Point(20, 8)))  
    // if (bsp(Point(7, 7), Point(11, 1), Point(2, 2), Point(7, 7.000001)))
       std::cout << "The point is inside triangle:" << std::endl; 
	else 
        std::cout << "The point is outside triangle:" << std::endl;
    return (0);
}