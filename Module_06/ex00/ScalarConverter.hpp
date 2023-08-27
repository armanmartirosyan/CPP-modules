#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <cctype>
# include <limits>
# include <sstream>

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
		static bool	checkOverflow(const std::string&, const bool);
		static void	convertToChar(const std::string&);
		static void	convetToInt(const std::string&);
		static void	convertToDoubleOrFloat(std::string);
		static void	convertToInf(std::string);

		static bool	isDot;

		// Variables
		enum {CHAR, INT, DOUBLE, FLOAT, INF, OVERFLOW,  ERROR};
};

#endif