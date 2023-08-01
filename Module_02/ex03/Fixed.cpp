#include "Fixed.hpp"

const int Fixed::_frac = 8;

Fixed::Fixed (void) {
	this->_fixed = 0;
}

Fixed::Fixed (const Fixed& obj) {
	*this = obj;
}

Fixed::Fixed (const int num) {
	this->_fixed = (num << Fixed::_frac);
}

Fixed::Fixed (const float num) {
	this->_fixed = roundf(num * (1 << Fixed::_frac));
}


Fixed::~Fixed (void) { }

// Operations

Fixed& Fixed::operator= (const Fixed& obj) {
	this->_fixed = obj._fixed;
	return (*this);
}

std::ostream& operator<< (std::ostream& output, const Fixed& obj) {
	output << obj.toFloat();
	return (output);
}

bool	Fixed::operator<(const Fixed& obj)  const {
	return (this->_fixed < obj._fixed);
}

bool	Fixed::operator<=(const Fixed& obj)  const {
	return (this->_fixed <= obj._fixed);
}

bool	Fixed::operator>(const Fixed& obj)  const {
	return (this->_fixed > obj._fixed);
}

bool	Fixed::operator>=(const Fixed& obj)  const {
	return (this->_fixed >= obj._fixed);
}

bool	Fixed::operator==(const Fixed& obj) const {
	return (this->_fixed == obj._fixed);
}

bool	Fixed::operator!=(const Fixed& obj) const {
	return (this->_fixed != obj._fixed);
}

Fixed	Fixed::operator+(const Fixed& obj)  const {
	return (this->toFloat() + obj.toFloat());
}

Fixed	Fixed::operator-(const Fixed& obj)  const {
	return (this->toFloat() - obj.toFloat());
}

Fixed	Fixed::operator*(const Fixed& obj)  const {
	return (this->toFloat() * obj.toFloat());
}

Fixed	Fixed::operator/(const Fixed& obj)  const {
	return (this->toFloat() / obj.toFloat());
}

Fixed&	Fixed::operator++(void) {
	++this->_fixed;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp;

	tmp = *this;
	this->_fixed++;
	return (tmp);
}

Fixed& Fixed::operator--(void) {
	--this->_fixed;
	return (*this);
}


Fixed	Fixed::operator--(int) {
	Fixed	tmp;

	tmp = *this;
	this->_fixed--;
	return (tmp);
}

// Functions

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

Fixed& Fixed::min(Fixed& ob1, Fixed& ob2) {
	return (ob1 < ob2 ? ob1 : ob2);
}

Fixed& Fixed::max(Fixed& ob1, Fixed& ob2) {
	return (ob1 > ob2 ? ob1 : ob2);
}

const Fixed& Fixed::max(const Fixed& ob1, const Fixed& ob2) {
	return (ob1 > ob2 ? ob1 : ob2);
}

const Fixed& Fixed::min(const Fixed& ob1, const Fixed& ob2) {
	return (ob1 < ob2 ? ob1 : ob2);
}