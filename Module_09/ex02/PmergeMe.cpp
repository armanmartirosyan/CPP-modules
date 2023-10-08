#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_vecSequence;
std::list<int> PmergeMe::_listSequence;

// Constructors
PmergeMe::PmergeMe(void) {
	return ;
}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	(void) rhs;
	return ;
}

// Destructor
PmergeMe::~PmergeMe(void) {
	return ;
}

// Operators
PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs) {
	(void) rhs;
	return (*this);
}

// Functions
bool	PmergeMe::positiveNumbers(const std::string& str) {
	for (size_t i = 0; i < str.size(); i++) {
		if(!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '+')
			return (false);
		if(str[i] == '+' && !std::isdigit(str[i + 1]))
			return (false);
	}
	return (true);
}

void	PmergeMe::fillContainers(const std::string&	str) {
	std::stringstream	ss(str), sp(str);
	std::string			tmp;
	long				num;

	while(sp >> tmp) {
		ss >> num;
		if (num <= 0)
			throw std::logic_error("Error: Negative number or zero.");
		if (num > std::numeric_limits<int>::max() || tmp.size() > 12)
			throw std::logic_error("Error: Overflow.");
		_vecSequence.push_back(static_cast<int>(num));
		_listSequence.push_back(static_cast<int>(num));
	}
	if(_vecSequence.empty() || _listSequence.empty())
		throw std::logic_error("Error: Empty sequence.");
	return ;
}

void	PmergeMe::printVector(const std::string& message) {
	std::cout << message << "\t[std::vector]: \t";

	if(_vecSequence.size() <= 13) {
		for(size_t i = 0; i < _vecSequence.size(); ++i) {
			std::cout << _vecSequence[i];
			if(i != _vecSequence.size() - 1)
				std::cout<<" ";
		}
	} else {
		for(size_t i = 0; i < 10; ++i)
			std::cout << _vecSequence[i] << " ";

		std::cout<<"[...] ";

		for(size_t i = _vecSequence.size() - 3; i < _vecSequence.size(); ++i) {
			std::cout << _vecSequence[i];
			if(i != _vecSequence.size() - 1)
				std::cout<<" ";
		}
	}
	std::cout<<std::endl;
	return ;
}

void	PmergeMe::printList(const std::string& message) {
	std::cout << message << "\t[std::list]: \t";

	if(_listSequence.size() <= 13) {
		for(std::list<int>::iterator it = _listSequence.begin(); it != _listSequence.end(); ++it) {
			std::cout<<*it;
			if(it != --_listSequence.end())
				std::cout<<" ";
		}
	} else {
		int printedCount = 0;
		for(std::list<int>::iterator it = _listSequence.begin(); printedCount != 10 && it != _listSequence.end(); ++it) {
			++printedCount;
			std::cout<<*it<<" ";
		}

		std::cout<<"[...] ";

		std::list<int>::iterator lastButOne = _listSequence.end();
		std::advance(lastButOne, -3);

		for(std::list<int>::iterator it = lastButOne; it != _listSequence.end(); ++it) {
			std::cout<<*it;
			if(it != --_listSequence.end())
				std::cout<<" ";
		}
	}
	std::cout<<std::endl;
	return ;
}

void	PmergeMe::FordJohnson(const std::string& str) {	
	_listSequence.clear();
	_vecSequence.clear();

	if(str.empty() || !positiveNumbers(str))
		throw std::logic_error(("Error: invalid argument."));

	fillContainers(str);

	printList("Before:");
	printVector("Before:");


	
	return ;
}