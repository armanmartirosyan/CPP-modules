#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <stdexcept>
# include <sstream>
# include <limits>

class PmergeMe {
	public:
		static void	FordJohnson(const std::string&);

	private:
		// Constructors
		PmergeMe(void);
		PmergeMe(const PmergeMe&);
		~PmergeMe(void);

		// Operations
		PmergeMe&	operator=(const PmergeMe&);

		// Functions
		static bool	positiveNumbers(const std::string&);
		static void	fillContainers(const std::string&);
		static void	printVector(const std::string&);
		static void	printList(const std::string&);

		// Variables
		static std::vector<int>	_vecSequence;
		static std::list<int>	_listSequence;
};

#endif