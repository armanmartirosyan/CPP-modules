#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat(void) : WrongAnimal::WrongAnimal() {
	this->setType("(WrongCat)");
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal::WrongAnimal(rhs) {
	this->setType("(WrongCat)");
	std::cout << "WrongCat copy constructor called" << std::endl;
	return ;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	WrongAnimal::operator=(rhs);
	std::cout << "WrongAnimal copy assignment constructor." << std::endl;
	return (*this);
}

// Destructor
WrongCat::~WrongCat(void) {
	std::cout << "WrongCat default destructor called" << std::endl;
}

// Functinos
void	WrongCat::makeSound(void) const {
	std::cout << "WrongCat: MEOW, MEOOOOOOOW!" << std::endl;
	return ;
}