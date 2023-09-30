#include "RPN.hpp"

// Constructors
RPN::RPN(void) {
	return ;
}

RPN::RPN(const std::string& input) {

	for (size_t i = 0; i < input.size(); i++) {
		if (std::isdigit(input.at(i)))
			this->_calc.push(std::atoi(input.substr(i, 1).c_str()));
		else if((input.at(i) == '+' || input.at(i) == '/' || input.at(i) == '*' || input.at(i) == '-')
				&& this->_calc.size() > 1)
			performOP(input.at(i));
		else if (std::isspace(input.at(i)))
			continue ;
		else {
			std::cerr << "Wrong Input." << std::endl;
			return ;
		}
	}
	if (this->_calc.size() > 1) {
		std::cerr << "Wrong Input." << std::endl;
		return ;
	}
	if (!this->_calc.empty())
		std::cout << this->_calc.top() << std::endl;
	return ;
}

RPN::RPN(const RPN& rhs) {
	this->_calc = rhs._calc;
	return ;
}

// Destructor
RPN::~RPN(void) {
	return ;
}

// Operations 
RPN& RPN::operator=(const RPN& rhs) {
	if (this == &rhs)
		return (*this);
	this->_calc = rhs._calc;
	return (*this);
}

// Functions
void	RPN::performOP(const char input) {
	double rVal, lVal, res;

	rVal = this->_calc.top();
	this->_calc.pop();

	lVal = this->_calc.top();
	this->_calc.pop();

	if (input == '-')
		res = lVal - rVal;
	else if (input == '+')
		res = lVal + rVal;
	else if (input == '/')
		res = lVal / rVal;
	else
		res = lVal * rVal;
	this->_calc.push(res);
	return ;
}