#pragma once 
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	public:
		// Constructors
		Animal(void);
		Animal(const Animal&);
		virtual ~Animal(void);

		// Operations
		Animal&	operator=(const Animal&);

		// Getters
		std::string getType(void) const;

		// Setters
		void	setType(const std::string&);

		// Functions
		virtual void	makeSound(void) const;
	protected:
		std::string	_type;
};

#endif