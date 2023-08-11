#pragma once 
#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog(void);
		Dog(const Dog&);
		~Dog(void);

		// Operations
		Dog& operator=(const Dog&);

		// Getters
		std::string	getDogIdea(const size_t&)	const;
		Brain&		getDogBrain(void) 			const;

		// Setters
		void	setDogIdea(size_t, const std::string&);
		void	setDogBrain(const Brain&);

		// Functions
		void	makeSound(void) const;
	private:
		Brain* _brain;
};

#endif