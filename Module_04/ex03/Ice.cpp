#include "Ice.hpp"

// Constructors
Ice::Ice(void) {
	this->_type = "ice";
	return ;
}

Ice::Ice(const Ice& rhs) {
	this->_type = rhs.getType();
	return ;
}

// Destructor
Ice::~Ice(void) {
	return ;
}

// Operators
Ice& Ice::operator=(const Ice& rhs) {
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

// Funtions
void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName() << " *" << std::endl;
	return ;
}

AMateria*	Ice::clone(void) const {
	AMateria* res = new Ice();
	return (res);
}