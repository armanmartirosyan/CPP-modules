#include "Cat.hpp"

// Constructors
Cat::Cat(void) : Animal::Animal() {
	this->setType("(Cat)");
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat& rhs) : Animal::Animal(rhs) {
	this->setType("(Cat)");
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat& Cat::operator=(const Cat& rhs) {
	Animal::operator=(rhs);
	std::cout << "Animal copy assignment constructor." << std::endl;
	return (*this);
}

// Destructor
Cat::~Cat(void) {
	std::cout << "Cat default destructor called" << std::endl;
}

// Functinos
void	Cat::makeSound(void) const {
	std::cout << "Cat: MEOW, MEOOOOOOOW!" << std::endl;
	return ;
}