#pragma once
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>

class RPN {
	public:
		// Constructors
		RPN(void);
		RPN(const std::string&);
		RPN(const RPN&);
		~RPN(void);

		// Operations
		RPN& operator=(const RPN&);

		// Functions
		void	performOP(const char);
	
	private:
		std::stack<double>	_calc;
};

#endif