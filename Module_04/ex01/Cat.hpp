#pragma once
#ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		// Constructors
		Cat(void);
		Cat(const Cat&);
		~Cat(void);

		// Operations
		Cat& operator=(const Cat&);

		// Getters
		std::string	getCatIdea(const size_t&)	const;
		Brain&		getCatBrain(void) 			const;

		// Setters
		void	setCatIdea(size_t, const std::string&);
		void	setCatBrain(const Brain&);

		// Functions
		void	makeSound(void) const;
	private:
		Brain* _brain;
};

#endif