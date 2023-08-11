#pragma once 
#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {
	public:
		// Constructors
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal&);
		~WrongAnimal(void);

		// Operations
		WrongAnimal&	operator=(const WrongAnimal&);

		// Getters
		std::string getType(void) const;

		// Setters
		void	setType(const std::string&);

		// Functions
		void	makeSound(void) const;
	protected:
		std::string	_type;
};

#endif