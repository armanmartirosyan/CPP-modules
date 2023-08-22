#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <cctype>
# include <limits>

class ScalarConverter {
	public:
		static void	convert(const std::string&);
	private:
		// Constructors
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter&);
		~ScalarConverter(void);

		// Operations
		ScalarConverter& operator=(const ScalarConverter&);

		// Functions
		static int	parsing(const std::string&);
		static int	parsingNumber(const std::string&);

		// Variables
		enum {CHAR, INT, DOUBLE, FLOAT, INF, ERROR};
};

#endif