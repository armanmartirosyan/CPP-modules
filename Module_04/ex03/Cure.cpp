#include "Cure.hpp"

// Constructors
Cure::Cure(void) {
	this->_type = "cure";
	return ;
}

Cure::Cure(const Cure& rhs) {
	this->_type = rhs.getType();
	return ;
}

// Destructor
Cure::~Cure(void) {
	return ;
}

// Operators
Cure& Cure::operator=(const Cure& rhs) {
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

// Funtions
void	Cure::use(ICharacter& target) {
	std::cout << "* heals "<< target.getName();
	std::cout << "’s wounds *" << std::endl;
	return ;
}

AMateria*	Cure::clone(void) const {
	AMateria* res = new Cure();
	return (res);
}