#include "Span.hpp"

#define MAX_VAL 15000

int main (void) {
	Span a(MAX_VAL);

	try {
		a.insert(1,15);
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
		try {
				a.insert(-1,15);
		} catch(const std::exception& e) {
			std::cout << e.what() << std::endl;
	}
	}
	for (size_t i = 10000; i != 0; --i)
		a.addNumber(i);
	a.insert(10000, 4999);
	a.addNumber(2000001);
	std::cout << "longest span: " << a.longestspan() << std::endl;
	std::cout << "shortest span: " << a.shortestspan() << std::endl;
	return (0);
}