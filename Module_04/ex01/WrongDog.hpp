#pragma once 
#ifndef WRONG_DOG_HPP
#define WRONG_DOG_HPP

# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
		// Constructors
		WrongDog(void);
		WrongDog(const WrongDog&);
		~WrongDog(void);

		// Operations
		WrongDog& operator=(const WrongDog&);

		// Functions
		void	makeSound(void) const;

};

#endif