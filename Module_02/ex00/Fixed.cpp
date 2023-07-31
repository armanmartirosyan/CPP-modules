#include "Fixed.hpp"

const int Fixed::_frac = 8;

Fixed::Fixed (void) {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

Fixed::Fixed (Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator= (Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed (void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void	Fixed::setRawBits (const int fixed) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = fixed;
	return ;
}
