#include "Span.hpp"

// Constructors
Span::Span(void) {
	this->_size = 0;
	return ;
}

Span::Span(unsigned int i) {
	this->_size = i;
	this->_arr.reserve(i);
	return ;
}

Span::Span(const Span& rhs) {
	this->_size = rhs._size;
	this->_arr = rhs._arr;
	return ;
}

// Destrutor
Span::~Span(void) {
	return ;
}

// Operations
Span&	Span::operator=(const Span& rhs) {
	if (this == &rhs)
		return (*this);
	this->_size = rhs._size;
	this->_arr = rhs._arr;
	return (*this);
}

// Functions
void	Span::printValue(void) {
	for (std::vector<int>::iterator it = this->_arr.begin(); it != this->_arr.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	return ;
}

void	Span::addNumber(int	num) {
	if (this->_arr.size() == this->_size)
		throw	std::out_of_range("Out of range!");
	this->_arr.push_back(num);
	return ;
}

void	Span::insert(size_t begin, size_t len) {
	if ((this->_arr.size() + len) > this->_size || begin > this->_arr.size())
		throw std::out_of_range("Out of range!");
	for (size_t i = 0; i < len; ++i)
		this->addNumber(++begin);
	return ;
}

int	Span::longestspan(void) {
	if (this->_arr.size() < 2)
		throw std::logic_error("Wrong input.");
	std::sort(this->_arr.begin(), this->_arr.end());
	return (this->_arr[this->_arr.size() - 1] - this->_arr[0]);
}

int	Span::shortestspan(void) {
	int min;

	if (this->_arr.size() < 2)
		throw std::logic_error("Wrong input.");
	std::sort(this->_arr.begin(), this->_arr.end());
	min = this->_arr.at(1) - this->_arr.at(0);
	for(size_t i = 1; i < this->_arr.size() - 1; ++i) {
		if (this->_arr.at(i + 1) - this->_arr.at(i) < min)
			min = this->_arr.at(i + 1) - this->_arr.at(i);
	} 
	return (min);
}