#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor." << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) {
	this->setType(rhs.getType());
	std::cout << "WrongAnimal copy constructor." << std::endl;
	return ;
}

// Destructor
WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal default destructor." << std::endl;
	return ;
}

// Operations
WrongAnimal& WrongAnimal::operator= (const WrongAnimal& rhs) {
	if (this == &rhs)
		return (*this);
	this->setType(rhs.getType());
	std::cout << "WrongAnimal copy assignment constructor." << std::endl;
	return (*this);
}

// Getters
std::string	WrongAnimal::getType(void) const {
	return (this->_type);
}

// Setters
void	WrongAnimal::setType(const std::string& type) {
	this->_type = type;
	return ;
}

// Functions
void	WrongAnimal::makeSound(void) const {
	std::cout << "*(Some WrongAnimal sound)*" << std::endl;
	return ;
}
