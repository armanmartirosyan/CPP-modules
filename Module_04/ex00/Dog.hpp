#pragma once 
#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog(void);
		Dog(const Dog&);
		~Dog(void);

		// Operations
		Dog& operator=(const Dog&);

		// Functions
		void	makeSound(void) const;

};

#endif