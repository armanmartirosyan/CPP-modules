#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

class Span {
	public:
		// Constructors
		Span(void);
		Span(unsigned int);
		Span(const Span&);
		~Span(void);

		// Operations
		Span& operator=(const Span&);

		// Functions
		int		shortestspan(void);
		int		longestspan(void);
		void	addNumber(int);
		void	insert(size_t, size_t);
		void	printValue(void);
	private:
		std::vector<int>	_arr;
		unsigned int		_size;
};


#endif