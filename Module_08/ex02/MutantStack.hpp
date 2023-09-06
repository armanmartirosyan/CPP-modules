#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		// Constructors
		MutantStack(void);
		MutantStack(const MutantStack&);
		~MutantStack(void);

		// Operations
		MutantStack&	operator=(const MutantStack&);

		// Iterators
		typedef typename std::stack<T, Container>::container_type::iterator					iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T, Container>::container_type::reverse_iterator			reverse_iterator;
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator	const_reverse_iterator;

		// Functions
		iterator				begin(void);
		iterator				end(void);
		reverse_iterator		rbegin(void);
		reverse_iterator		rend(void);
		const_iterator			begin(void)		const;
		const_iterator			end(void)		const;
		const_reverse_iterator	rbegin(void)	const;
		const_reverse_iterator	rend(void)		const;

};

# include "MutantStack.tpp"

#endif