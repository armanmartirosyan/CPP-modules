#include "Dog.hpp"

// Constructors
Dog::Dog(void) : Animal::Animal() {
	this->setType("(Dog)");
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog& rhs) : Animal::Animal(rhs) {
	this->setType("(Dog)");
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog& Dog::operator=(const Dog& rhs) {
	Animal::operator=(rhs);
	std::cout << "Dog copy assignment constructor." << std::endl;
	return (*this);
}

// Destructor
Dog::~Dog(void) {
	std::cout << "Dog default destructor called" << std::endl;
}

// Functinos
void	Dog::makeSound(void) const {
	std::cout << "Dog: haf, haf?" << std::endl;
	return ;
}