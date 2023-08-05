#include "WrongDog.hpp"

// Constructors
WrongDog::WrongDog(void) : WrongAnimal::WrongAnimal() {
	this->setType("(WrongDog)");
	std::cout << "WrongDog default constructor called" << std::endl;
	return ;
}

WrongDog::WrongDog(const WrongDog& rhs) : WrongAnimal::WrongAnimal(rhs) {
	this->setType("(WrongDog)");
	std::cout << "WrongDog copy constructor called" << std::endl;
	return ;
}

WrongDog& WrongDog::operator=(const WrongDog& rhs) {
	WrongAnimal::operator=(rhs);
	std::cout << "WrongAnimal copy assignment constructor." << std::endl;
	return (*this);
}

// Destructor
WrongDog::~WrongDog(void) {
	std::cout << "WrongDog default destructor called" << std::endl;
}

// Functinos
void	WrongDog::makeSound(void) const {
	std::cout << "WrongDog: haf, haf?" << std::endl;
	return ;
}