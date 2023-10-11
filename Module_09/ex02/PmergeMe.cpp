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

// Iteratirs
template <typename Iterator>
Iterator	PmergeMe::myNext(Iterator it, typename std::iterator_traits<Iterator>::difference_type n) {
	while (n > 0) {
		++it;
		--n;
	}
	return (it);
}

template <typename Iterator>
Iterator	PmergeMe::myPrev(Iterator it, typename std::iterator_traits<Iterator>::difference_type n) {
	while (n > 0) {
		--it;
		--n;
	}
	return (it);
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
				std::cout << " ";
		}
	} else {
		for(size_t i = 0; i < 10; ++i)
			std::cout << _vecSequence[i] << " ";

		std::cout<<"[...] ";

		for(size_t i = _vecSequence.size() - 3; i < _vecSequence.size(); ++i) {
			std::cout << _vecSequence[i];
			if(i != _vecSequence.size() - 1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
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
			std::cout << *it << " ";
		}

		std::cout << "[...] ";

		std::list<int>::iterator lastButOne = _listSequence.end();
		std::advance(lastButOne, -3);

		for(std::list<int>::iterator it = lastButOne; it != _listSequence.end(); ++it) {
			std::cout << *it;
			if(it != --_listSequence.end())
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return ;
}

void PmergeMe::vectorInsertion(std::vector<int>& nums) {
	for(size_t i = 1; i < nums.size(); ++i) {
		int j = i;
		while(j > 0 && nums[j] < nums[j - 1]) {
			std::swap(nums[j], nums[j - 1]);
			j--;
		}
	}
	return ;
}

void PmergeMe::vectorInsert(std::vector<int>& bigNums, std::vector<int>& smallNums) {
	int n = 0;
	int power = 0;
	size_t start_index = 0;
	size_t end_index = 0;

	for(size_t i = 0; i < smallNums.size();) {
		++power;
		n = pow(2, power) - n;
		start_index += n;
		end_index = start_index - n;

		if(start_index > smallNums.size())
			start_index = smallNums.size();

		for(size_t j = start_index - 1; j >= end_index;) {
			bigNums.insert(std::upper_bound(bigNums.begin(), bigNums.end(), smallNums[j]), smallNums[j]);
			++i;
			if(j == 0)
				break;
			--j;
		}
	}
	return ;
}

void	PmergeMe::sortVectorAlgorithm(std::vector<int>& nums) {
	int unpaired;
	std::vector<int> bigNums, smallNums;
	size_t size = nums.size() / 2 + (nums.size() % 2);

	unpaired = ((nums.size() % 2 == 0) ? -1 : nums[nums.size() - 1]);
	if(nums.size() == 2 || nums.size() == 3) {
		vectorInsertion(nums);
		return;
	}

	for(size_t i = 0; i < size; ++i) {
		if(i != size - 1 || nums.size() % 2 == 0) {
			int n = nums[i * 2], m = nums[i * 2 + 1];
			if(n > m)
				std::swap(n, m);
			bigNums.push_back(m);
			smallNums.push_back(n);
		}
	}
	if(unpaired != -1)
		smallNums.push_back(unpaired);	
	sortVectorAlgorithm(bigNums);
	vectorInsert(bigNums, smallNums);
	nums = bigNums;
	return ;
}

double	PmergeMe::sortVector(void) {
	clock_t start = clock();
	if(_vecSequence.size() != 1) sortVectorAlgorithm(_vecSequence);
	clock_t end = clock();

	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

	return (duration);
}

void	PmergeMe::listInsertion(std::list<int>& nums) {
	for(std::list<int>::iterator i = myNext(nums.begin()); i != nums.end(); ++i) {
		int	tmp = *i;
		std::list<int>::iterator j = i;
		while(j != nums.begin() && *myPrev(j) > tmp) {
			*j = *myPrev(j);
			j--;
		}
		*j = tmp;
	}
	return ;
}

void	PmergeMe::listInsert(std::list<int>& bigNums, std::list<int>& smallNums) {
	int n = 0;
	int power = 0;
	std::list<int>::iterator	start_index = bigNums.begin();
	std::list<int>::iterator	end_index = start_index;

	for(std::list<int>::iterator it = smallNums.begin(); it != smallNums.end();) {
		++power;
		n = pow(2, power) - n;
		std::advance(start_index, n);
		end_index = start_index;
		std::advance(end_index, -n);

		if(start_index != smallNums.end())
			start_index = smallNums.end();

		for(std::list<int>::iterator j = myPrev(start_index); j != myPrev(end_index);) {
			bigNums.insert(std::upper_bound(bigNums.begin(), bigNums.end(), *j), *j);
			++it;
			if(j == smallNums.begin())
				break;
			--j;
		}
	}
	return ;
}

void		PmergeMe::sortListAlgorithm(std::list<int>& nums) {
	int unpaired;
	std::list<int> bigNums, smallNums;
	size_t size = nums.size() / 2 + (nums.size() % 2);

	unpaired = ((nums.size() % 2 == 0) ? -1 : nums.back());
	if(nums.size() == 2 || nums.size() == 3) {
		listInsertion(nums);
		return;
	}

	for(size_t i = 0; i < size; ++i) {
		if(i != size - 1 || nums.size() % 2 == 0) {
			int	n = *myNext(nums.begin(), i * 2);
			int	m = *myNext(nums.begin(), i * 2 + 1);
			if(n > m)
				std::swap(n, m);
			bigNums.push_back(m);
			smallNums.push_back(n);
		}
	}
	if(unpaired != -1)
		smallNums.push_back(unpaired);	
	sortListAlgorithm(bigNums);
	listInsert(bigNums, smallNums);
	nums = bigNums;
	return ;
}

double PmergeMe::sortList(void) {
	clock_t start = clock();
	if(_listSequence.size() != 1) sortListAlgorithm(_listSequence);
	clock_t end = clock();

	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;

	return (duration);
}

void	PmergeMe::FordJohnson(const std::string& str) {	
	_listSequence.clear();
	_vecSequence.clear();

	if(str.empty() || !positiveNumbers(str))
		throw std::logic_error(("Error: invalid argument."));

	fillContainers(str);

	printList("Before:");
	printVector("Before:");

	double	vecTime, listTime;

	vecTime = sortVector();
	listTime = sortList();

	printList("After:");
	printVector("After:");

	std::cout<<"Time to process a range of "<< _vecSequence.size() << " elements with std::vector :\t" << vecTime << "\tmilliseconds" << std::endl;
	std::cout<<"Time to process a range of "<< _listSequence.size() << " elements with std::list   :\t" << listTime << "\tmilliseconds" << std::endl;

	return ;
}