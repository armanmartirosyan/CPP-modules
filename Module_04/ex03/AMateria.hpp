#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria {
	public:
		// Constructors
		AMateria(void);
		AMateria(const std::string&);
		AMateria(const AMateria&);
		virtual ~AMateria(void);

		// Operations
		AMateria& operator=(const AMateria&);
		
		// Getters
		const std::string& getType(void) const;

		// Functions
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter&);
	protected:
		std::string _type;
};

#endif