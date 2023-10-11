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
# include <ctime>
# include <cmath>
# include <algorithm>
# include <iterator> 

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

		// Iterators
  		template <typename Iterator>
		static Iterator	myNext(Iterator, typename std::iterator_traits<Iterator>::difference_type n = 1);
		template <typename Iterator>
		static Iterator	myPrev(Iterator, typename std::iterator_traits<Iterator>::difference_type n = 1);

		// Functions
		static bool		positiveNumbers(const std::string&);
		static void		fillContainers(const std::string&);
		static void		printVector(const std::string&);
		static void		printList(const std::string&);
		static void		vectorInsert(std::vector<int>&, std::vector<int>&);
		static void		vectorInsertion(std::vector<int>&);
		static void		sortVectorAlgorithm(std::vector<int>&);
		static double	sortVector(void);
		static void		listInsert(std::list<int>&, std::list<int>&);
		static void		listInsertion(std::list<int>&);
		static void		sortListAlgorithm(std::list<int>&);
		static double	sortList(void);

		// Variables
		static std::vector<int>	_vecSequence;
		static std::list<int>	_listSequence;
};

#endif