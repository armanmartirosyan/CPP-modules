#pragma once
#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria {
	public:
		// Constructors
		Cure(void);
		Cure(const Cure&);
		~Cure(void);

		// Operators
		Cure& operator= (const Cure&);

		// Functions
		void		use(ICharacter&);
		AMateria*	clone(void) const;
};

#endif