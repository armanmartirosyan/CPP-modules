#pragma once
#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		// Constructors
		Ice(void);
		Ice(const Ice&);
		~Ice(void);

		// Operators
		Ice& operator= (const Ice&);

		// Functions
		void		use(ICharacter&);
		AMateria*	clone(void) const;
};

#endif