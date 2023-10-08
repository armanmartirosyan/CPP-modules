#include "PmergeMe.hpp"

int main (int argc, char **argv) {
	std::string	sequence;

	for (int i = 1; i < argc; i++) {
		sequence += argv[i];
		sequence += " ";
	}

	// std::cout << sequence << std::endl;
	try {
		PmergeMe::FordJohnson(sequence);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}