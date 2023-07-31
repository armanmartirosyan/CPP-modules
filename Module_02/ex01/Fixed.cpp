#include "Fixed.hpp"

const int Fixed::_frac = 8;

Fixed::Fixed (void) {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

Fixed::Fixed (const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed (const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = (num << Fixed::_frac);
}

Fixed::Fixed (const float num) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(num * (1 << Fixed::_frac));
}

Fixed& Fixed::operator= (const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = obj._fixed;
	return (*this);
}

std::ostream& operator<< (std::ostream& output, const Fixed& obj) {
	output << obj.toFloat();
	return (output);
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

float	Fixed::toFloat(void) const {
	return ((float)this->_fixed / (1 << Fixed::_frac));
}

int		Fixed::toInt(void) const {
	return (this->_fixed >> Fixed::_frac);
}
