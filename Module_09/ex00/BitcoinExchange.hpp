#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <algorithm>
# include <fstream>
# include <cstdlib>
# include <ctime>

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
		void	exchangeBtc(const std::string&, const std::string&);
		void	readInput(const std::string&);
		bool	isLeapYear(int)										const;
		bool	isValidDate(int, int, int)							const;
		void	removeWhitespace(std::string&)						const;
		bool	isNumeric(const std::string&)						const;
		bool	checkDate(const std::string&)						const;
		bool	checkValue(const std::string&)						const;
	private:
		std::map<std::string, double>	_csvValue;
		
};


#endif