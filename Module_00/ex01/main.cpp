#include "PhoneBook.hpp"


int main() {
	PhoneBook 	p;
	std::string	input;

	while (1) {
		do {
			std::cout << "Use following commands: ADD -- SEARCH -- EXIT;" << std::endl;
			std::cin >> input;
		} while (p.check_input(input, 0));
		if (input == "add")
			p.setContact();
		else if (input == "search")
			p.search();
		else if (input == "exit")
			break;
	}
	return (0);
}