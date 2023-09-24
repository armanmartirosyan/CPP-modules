#include "BitcoinExchange.hpp"


// Constructors
BitcoinExchange::BitcoinExchange(void) {
	std::ifstream inputFile;

	inputFile.open("./data.csv");

	if (!inputFile.is_open()) {
		throw (std::logic_error("Error: could not open file."));
	}
	std::string						line;
	std::pair<std::string, float>	pair;
	std::size_t						found;
	std::size_t						row = 1;
	while (std::getline(inputFile, line)) {
		removeWhitespace(line);
		found = line.find(",");
		if (found == std::string::npos) {
			std::cerr << "Error: invalid value." << std::endl;
			continue ;
		}
		if (!checkDate(line.substr(0, found)) || !checkValue(line.substr(found + 1))) {
			std::cerr << "Error: invalid date in line " << row << std::endl;
			continue ;
		}

		row++;
	}
	inputFile.close();
	return ;
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {

// 	return ;
// }

BitcoinExchange::~BitcoinExchange(void) {
	return ;
}

// Functions
void	BitcoinExchange::removeWhitespace(std::string& line) {
	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
	return ;
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	BitcoinExchange::isValidDate(int day, int month, int year) {
    if (year < 2008 || year > 9999)
        return (false);

    if (month < 1 || month > 12)
        return (false);

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        daysInMonth[2] = 29;

    return (day >= 1 && day <= daysInMonth[month]);
}

bool isNumeric(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it)) {
            return (false);
        }
    }
    return (true);
}

bool	BitcoinExchange::checkDate(const std::string& date) {
	std::size_t	pos;
	std::size_t	exPos = 0;
	int			year;
	int			month;
	int			day;
	std::string	tmp;

	pos = date.find("-");
	if (pos == std::string::npos)
		return (true);
	tmp = date.substr(exPos, pos);
	year = std::atoi(tmp.c_str());
	exPos = pos + 1;
	pos = date.find("-", pos + 1);
	if (pos == std::string::npos)
		return (true);
	tmp = date.substr(exPos, pos - exPos);
	month = std::atoi(tmp.c_str());
	tmp = date.substr(pos + 1);
	day = std::atoi(tmp.c_str());
	return (isNumeric(tmp) && isValidDate(day, month, year));
}

bool	BitcoinExchange::checkValue(const std::string& value) {
	int	isDot = 0;
	std::cout << value << std::endl;
	for (size_t i = 0; i < value.length(); i++) {
		if (!isdigit(value[i])) {
			if (value[i] == '.') {
				isDot++;
			}
			else
				return (false);
		}
	}
	
	return (isDot <= 1 ? true : false);
}