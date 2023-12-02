#include "BitcoinExchange.hpp"

# define DATABASE "./data.csv"
# define EROPEN "Error: could not open file."
# define ENOTPOS "Error: not a positive number."
# define ELNUM	"Error: too large a number."
# define ESUITVAL "Error: No suitable value"
# define EBADIN	"Error: bad input => "

// Constructors
BitcoinExchange::BitcoinExchange(void) {
	std::ifstream inputFile;

	inputFile.open(DATABASE);

	if (!inputFile.is_open())
		throw (std::logic_error(EROPEN));
	std::string						line;
	std::string::size_type			found;

	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		removeWhitespace(line);
		found = line.find(",");
		if (found == std::string::npos) {
			std::cerr << EBADIN << line << std::endl;
			continue ;
		}
		if (!checkDate(line.substr(0, found)) || !checkValue(line.substr(found + 1))) {
			std::cerr << EBADIN << line.substr(0, found) << std::endl;
			continue ;
		}
		this->_csvValue[line.substr(0, found)] = std::atof(line.substr(found + 1).c_str());
	}
	inputFile.close();
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {
	this->_csvValue = rhs._csvValue;
	return ;
}

BitcoinExchange::~BitcoinExchange(void) {
	return ;
}

// Operations
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this == &rhs)
		return (*this);
	this->_csvValue = rhs._csvValue;
	return (*this);
}

// Functions
// Validation
void	BitcoinExchange::removeWhitespace(std::string& line) const {
	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
	return ;
}

bool BitcoinExchange::isLeapYear(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	BitcoinExchange::isValidDate(int day, int month, int year) const {
	std::time_t currentTime;
	std::time(&currentTime);
	std::tm dateStruct = {};

	dateStruct.tm_year = year - 1900;
	dateStruct.tm_mon = month - 1;
	dateStruct.tm_mday = day;
	dateStruct.tm_hour = 0;
	dateStruct.tm_min = 0;
	dateStruct.tm_sec = 0;
	std::time_t dbDate = std::mktime(&dateStruct);
	if (year <= 2008 || currentTime < dbDate)
		return (false);
	if (month < 1 || month > 12)
		return (false);

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		daysInMonth[2] = 29;
	return (day >= 1 && day <= daysInMonth[month]);
}

bool BitcoinExchange::isNumeric(const std::string& str) const {
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (!isdigit(*it)) {
			return (false);
		}
	}
	return (true);
}

bool	BitcoinExchange::checkDate(const std::string& date) const {
	std::size_t	pos;
	std::size_t	exPos = 0;
	int			year;
	int			month;
	int			day;
	std::string	tmp;

	pos = date.find("-");
	if (pos == std::string::npos || pos != 4)
		return (false);
	tmp = date.substr(exPos, pos);
	year = std::atoi(tmp.c_str());
	exPos = pos + 1;
	pos = date.find("-", pos + 1);
	if (pos == std::string::npos || pos != 7)
		return (false);
	tmp = date.substr(exPos, pos - exPos);
	month = std::atoi(tmp.c_str());
	tmp = date.substr(pos + 1);
	if (tmp.length() != 2)
		return (false);
	day = std::atoi(tmp.c_str());
	return (isNumeric(tmp) && isValidDate(day, month, year));
}

bool	BitcoinExchange::checkValue(const std::string& value) const {
	int	isDot = 0;
	int	isMinus = 0;
	int	isPlus = 0;
	if (value.empty() || value[0] == '.' || value[value.length() - 1] == '.')
		return (false);
	for (size_t i = 0; i < value.length(); i++) {
		if (!isdigit(value[i])) {
			if (value[i] == '.')
				isDot++;
			else if (value[i] == '+')
				isPlus++;
			else if (value[i] == '-')
				isMinus++;
			else
				return (false);
		}
	}
	if (isDot <= 1 && (isPlus <= 1 || isMinus <= 1))
		return (true);
	return (false);
}

// Exchange bitcoin
void	BitcoinExchange::exchangeBtc(const std::string& date, const std::string& value) {
	std::map<std::string, double>::iterator	it = this->_csvValue.find(date);
	double									valFloat = std::atof(value.c_str());

	if (valFloat < 0) {
		std::cerr << ENOTPOS << std::endl;
		return ;
	}
	if (valFloat > 1000) {
		std::cerr << ELNUM << std::endl;
		return ;
	}
	if (it != this->_csvValue.end())
		std::cout << date << " => " << valFloat << " = " << it->second * valFloat << std::endl;
	else {
		it = this->_csvValue.upper_bound(date);
		if (it == this->_csvValue.begin()) {
			std::cerr << ESUITVAL << std::endl;
			return ;
		}
		--it;
		std::cout << date << " => " << valFloat << " = " << it->second * valFloat << std::endl;
	}
	return ;
}

void	BitcoinExchange::readInput(const std::string& name) {
	std::ifstream inputFile;

	inputFile.open(name.c_str());

	if (!inputFile.is_open())
		throw (std::logic_error(EROPEN));
	std::string								line;
	std::string::size_type					found;
	std::map<std::string, double>::iterator	it;

	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		removeWhitespace(line);
		found = line.find("|");
		if (found == std::string::npos) {
			std::cerr << EBADIN << line << std::endl;
			continue ;
		}
		if (!checkDate(line.substr(0, found)) || !checkValue(line.substr(found + 1))) {
			std::cerr << EBADIN << line.substr(0, found) << std::endl;
			continue ;
		}
		exchangeBtc(line.substr(0, found), line.substr(found + 1));
	}
	inputFile.close();
	return ;
}