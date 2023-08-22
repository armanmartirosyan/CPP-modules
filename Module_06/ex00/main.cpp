#include "ScalarConverter.hpp"
#include <iostream>

int main (int argc, char** argv) {
	(void)argc;
	std::string str(argv[1]);
	ScalarConverter::convert(str);
	return (0);
}