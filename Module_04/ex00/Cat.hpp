#pragma once
#ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public:
		// Constructors
		Cat(void);
		Cat(const Cat&);
		~Cat(void);

		// Operations
		Cat& operator=(const Cat&);

		// Functions
		void	makeSound(void) const;
};

#endif