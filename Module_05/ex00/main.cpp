#include "Bureaucrat.hpp"

int main (void) {
	Bureaucrat John(1, "John");
	
	while (John.getGrade() < 151) {
		try {
			John--;
			std::cout << John;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
	return (0);
}