#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <string>
# define IDLIMIT 100

class Brain {
	public:
		// constructors
		Brain(void);
		Brain(const Brain&);
		~Brain(void);

		// operations
		Brain& operator=(const Brain&);

		// Getters
		std::string getIdea(size_t) const;

		// Setters
		void	setIdea(size_t, const std::string&);
	private:
		std::string	_ideas[IDLIMIT];
};

#endif