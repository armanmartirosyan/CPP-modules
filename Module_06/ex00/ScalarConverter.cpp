# include "ScalarConverter.hpp"

// Variables
bool ScalarConverter::isDot = false;

// Constructors
ScalarConverter::ScalarConverter(void) {
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs) {
	(void)rhs;
	return ;
}

// Destructor
ScalarConverter::~ScalarConverter(void) {
	return ;
}

// Operations
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& rhs) {
	(void)rhs;
	return (*this);
}

// Functions
// Converts
void	ScalarConverter::convertToChar(const std::string& input) {
	std::cout << "char: \'" << static_cast<char>(input[0]) << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
	return ;
}

void	ScalarConverter::convetToInt(const std::string& input) {
	int		num = std::atoi(input.c_str());
	char	charValue = static_cast<char>(num);
	
	std::cout << "char: ";
	if (isascii(num) && std::isprint(num))
		std::cout << "\'" << charValue << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
	return ;
}

void	ScalarConverter::convertToDoubleOrFloat(std::string input) {
	double	num(0);
	char	charValue;

	if (input[input.length() - 1] == 'f')
		input.erase(input.length() - 1, 1);
	std::istringstream iss(input.c_str());
	if (!(iss >> num)) {
		throw	std::invalid_argument("Convert exception");
	}
	charValue = static_cast<char>(num);
	std::cout << "char: ";
	if (isascii(num) && std::isprint(charValue))
		std::cout << "\'" << charValue << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << static_cast<float>(num) 
	<< ((isDot || static_cast<float>(num) == std::numeric_limits<float>::infinity()) ? "f" : ".0f") << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ((isDot) ? "" : ".0") << std::endl;
	return ;
}

void	ScalarConverter::convertToInf(std::string input) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (!input.compare("-inff") || !input.compare("+inff")
		|| !input.compare("nanf") || !input.compare("inff"))
		input.erase(input.length() - 1, 1);
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
	return ;
}

// Parsing
bool	ScalarConverter::checkOverflow(const std::string& input, const bool isSign) {
	size_t	overflowLen = (isSign) ? 10 : 9;

	if (overflowLen > input.length())
		return (false);
	long		num = std::stol(input.c_str(), NULL, 10);
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		return (true);
	return (false);
}

int	ScalarConverter::parsingNumber(const std::string& input) {
	size_t	i = 0;
	bool	isInteger = true;
	bool	isDouble = true;
	bool	isSign = false;
	int		dotIndex;

	
	if (input[i] == '+' || input[i] == '-') {
		i++;
		isSign = true;
	}
	for (; i < input.length() && isInteger; ++i) {
		if (!std::isdigit(input[i])) {
			isInteger = false;
			break;
		}
	}
	if (isInteger) {
		if  (isSign && input.length() > 11)
			return (DOUBLE);
		if (!isSign && input.length() > 10)
			return (DOUBLE);
		if (checkOverflow(input, isSign))
			return (DOUBLE);
		return (INT);
	}
	if (input[i++] != '.' || i == input.length())
		return (ERROR);
	isDot = true;
	dotIndex = i - 1;
	for (; i < input.length(); ++i) {
		if (!std::isdigit(input[i])) {
			isDouble = false;
			break;
		}
	}
	if (isDouble)
		return (DOUBLE);
	if (std::isdigit(input[i - 1]) && i == input.length() - 1 && input[i] == 'f')
		return (FLOAT);
	return (ERROR);
}

int	ScalarConverter::parsing(const std::string& input) {
	if(input.size() == 1 && (std::isprint(input[0]) && !std::isdigit(input[0])))
		return (CHAR);
	if(!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf") || !input.compare("inf") 
		|| !input.compare("-inf") || !input.compare("+inf") || !input.compare("nan") || !input.compare("inff"))
			return (INF);
	return (parsingNumber(input));	
}

void ScalarConverter::convert(const std::string& input) {
	if (input.empty())
		throw std::invalid_argument("Input is empty.");
	switch (parsing(input))
	{
	case CHAR:
		convertToChar(input);
		break;
	case INT:
		convetToInt(input);
		break;
	case DOUBLE:
		convertToDoubleOrFloat(input);
		break;
	case FLOAT:
		convertToDoubleOrFloat(input);
		break;
	case INF:
		convertToInf(input);
		break;
	default:
		throw std::invalid_argument("Invalid Argument!");
		break;
	}
}