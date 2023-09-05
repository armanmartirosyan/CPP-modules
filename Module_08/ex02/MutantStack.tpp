#pragma once
#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

// Constructors
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) {
	return ;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& rhs) {
	*this = rhs;
	return ;
} 

// Destructor
template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) {
	return ;
}

// Operations
template <typename T, typename Container>
MutantStack<T, Container>&	MutantStack<T,Container>::operator=(const MutantStack& rhs) {
	if (this == &rhs)
		return (*this);
	std::stack<T, Container>::operator=(rhs);
	return (*this);
}

// Functions
template <typename T, typename Container>
typename std::stack<T, Container>::container_type::iterator	MutantStack<T, Container>::begin(void) {
	return (this->std::stack<T, Container>::c.begin());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::iterator MutantStack<T, Container>::end(void) {
	return (this->std::stack<T, Container>::c.end());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::reverse_iterator MutantStack<T, Container>::rbegin(void) {
	return (this->std::stack<T, Container>::c.rbegin());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::reverse_iterator MutantStack<T, Container>::rend(void) {
	return (this->std::stack<T, Container>::c.rend());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::const_iterator MutantStack<T, Container>::begin(void) const {
	return (this->std::stack<T, Container>::c.begin());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::const_iterator MutantStack<T, Container>::end(void) const {
	return (this->std::stack<T, Container>::c.end());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::const_reverse_iterator MutantStack<T, Container>::rbegin(void) const {
	return (this->std::stack<T, Container>::c.rbegin());
}

template <typename T, typename Container>
typename std::stack<T, Container>::container_type::const_reverse_iterator MutantStack<T, Container>::rend(void) const {
	return (this->std::stack<T, Container>::c.rend());
}

#endif