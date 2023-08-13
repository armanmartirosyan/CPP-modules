#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		// Constructors
		MateriaSource(void);
		MateriaSource(const MateriaSource&);
		~MateriaSource(void);

		// Operators
		MateriaSource& operator=(const MateriaSource&);

		// Getters
		AMateria&	getSpell(size_t)	const;

		// Functions
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
	private:
		AMateria*	_spells[4];
};

#endif