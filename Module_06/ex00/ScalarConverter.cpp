# include "ScalarConverter.hpp"

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
int	ScalarConverter::parsingNumber(const std::string& input) {
	size_t	i = 0;
	bool	isInteger = true;
	bool	isDouble = true;

	
	if (input[i] == '+' || input[i] == '-')
		i++;
	for (; i < input.length() && isInteger; ++i) {
		if (!std::isdigit(input[i])) {
			isInteger = false;
			break;
		}
	}
	if (isInteger)
		return (INT);
	if (input[i++] != '.' || i == input.length())
		return (ERROR);
	for (; i < input.length(); ++i) {
		if (!std::isdigit(input[i])){
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
	if(input.size() == 1 && (isprint(input[0]) && !isdigit(input[0])))
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
		std::cout << "CHAR:" << std::endl;
		break;
	case INT:
		std::cout << "INT:" << std::endl;
		break;
	case DOUBLE:
		std::cout << "DOUBLE:" << std::endl;
		break;
	case FLOAT:
		std::cout << "FLOAT:" << std::endl;
		break;
	default:
		std::cout << "ERROR:" << std::endl;
		break;
	}
}