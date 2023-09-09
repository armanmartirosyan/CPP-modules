# include <iostream>
# include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	char g = 'f';
	char f = 'g';
	::swap(g, f);
	std::cout << "g = " << g << ", f = " << f << std::endl;
	std::cout << "min(g, f) = " << ::min(g, f) << std::endl;
	std::cout << "max(g, f) = " << ::max(g, f) << std::endl;
	double num1 = 1.123;
	double num2 = 1.234;
	::swap(num1, num2);
	std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
	std::cout << "min(num1, num2) = " << ::min(num1, num2) << std::endl;
	std::cout << "max(num1, num2) = " << ::max(num1, num2) << std::endl;
	return (0);
}