#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <algorithm>
# include <fstream>
# include <cstdlib>

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange&);
		~BitcoinExchange(void);

		// Operations
		BitcoinExchange& operator=(const BitcoinExchange&);

		// Functinos
		bool	isLeapYear(int);
		bool	isValidDate(int, int, int);
		void	removeWhitespace(std::string&);
		bool	checkDate(const std::string&);
		bool	checkValue(const std::string&);
	private:
		std::map<std::string, float>	_csvValue;
		
};


#endif