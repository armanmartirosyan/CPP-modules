#pragma once
#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		// Constructors
		WrongCat(void);
		WrongCat(const WrongCat&);
		~WrongCat(void);

		// Operations
		WrongCat& operator=(const WrongCat&);

		// Functions
		void	makeSound(void) const;
};

#endif