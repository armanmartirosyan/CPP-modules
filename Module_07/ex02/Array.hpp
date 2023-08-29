#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept> 

template<typename T>
class Array {
	public:
		// Construstrors
		Array(void);
		Array(unsigned int);
		Array(const Array&);
		~Array(void);

		// Operations
		Array<T>&	operator=(const Array&);
		T&			operator[](unsigned int);

		// Functions
		unsigned int	size(void)	const;
	private:
		unsigned int	_size;
		T				*_data;
};

# include "Array.tpp"

#endif