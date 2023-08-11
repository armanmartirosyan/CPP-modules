#include "AMateria.hpp"

// Constructors
AMateria::AMateria(void) {
	this->_type = ("No Type");
	return ;
}

AMateria::AMateria(const std::string& type) {
	this->_type = type;
	return ;
}

AMateria::AMateria(const AMateria& rhs) {
	this->_type = rhs.getType();
	return ;
}

// Destructor
AMateria::~AMateria(void) {
	return ;
}

// Operations
AMateria&	AMateria::operator=(const AMateria& rhs) {
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

// Getters
const std::string&	AMateria::getType(void) const {
	return (this->_type);
}

// Functions
void	AMateria::use(ICharacter& ch) {
	(void)ch;
	return ;
}