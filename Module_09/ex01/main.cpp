#include "RPN.hpp"

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Invalid amount of arguments." << std::endl;
		return (1);
	}
	std::string	input(argv[1]);
	RPN reversePolishNotation(input);
	return (0);
}