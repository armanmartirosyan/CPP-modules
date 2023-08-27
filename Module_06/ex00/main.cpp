#include "ScalarConverter.hpp"
#include <iostream>

int main (int argc, char** argv) {
	std::string	input;
	(void)argc;

	for(int i = 1; i < argc; ++i) {
		input = argv[i];
		try {
			ScalarConverter::convert(input);
		} catch (std::invalid_argument e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
