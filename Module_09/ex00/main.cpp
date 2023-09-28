#include "BitcoinExchange.hpp"

int main (int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		return (1);
	}
	BitcoinExchange btc;
	btc.readInput(argv[1]);
	
	return (0);
}