#include "Animal.hpp"

// Constructors
Animal::Animal(void) {
	std::cout << "Animal default constructor." << std::endl;
	return ;
}

Animal::Animal(const Animal& rhs) {
	this->setType(rhs.getType());
	std::cout << "Animal copy constructor." << std::endl;
	return ;
}

// Destructor
Animal::~Animal(void) {
	std::cout << "Animal default destructor." << std::endl;
	return ;
}

// Operations
Animal& Animal::operator= (const Animal& rhs) {
	if (this == &rhs)
		return (*this);
	this->setType(rhs.getType());
	std::cout << "Animal copy assignment constructor." << std::endl;
	return (*this);
}

// Getters
std::string	Animal::getType(void) const {
	return (this->_type);
}

// Setters
void	Animal::setType(const std::string& type) {
	this->_type = type;
	return ;
}
