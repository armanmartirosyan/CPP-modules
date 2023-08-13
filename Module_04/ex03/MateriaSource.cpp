#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource(void) {
	for (size_t i = 0; i < INVLIMIT; ++i)
		this->_spells[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource& rhs) {
	for (size_t i = 0; i < INVLIMIT; ++i)
		this->_spells[i] = &rhs.getSpell(i);
	return ;
}

// Destructors
MateriaSource::~MateriaSource(void) {
	for (size_t i = 0; i < INVLIMIT; ++i)
		delete this->_spells[i];
	return ;
}

// Operators
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	if (this == &rhs)
		return (*this);
	for (size_t i = 0; i < INVLIMIT; ++i) {
		delete this->_spells[i];
		this->_spells[i] = &rhs.getSpell(i);
	}
	return (*this);
}

// Getters
AMateria&	MateriaSource::getSpell(size_t i) const {
	return *(this->_spells[i]);
}

// Functions
void	MateriaSource::learnMateria(AMateria* m) {
	static size_t	i;

	if (i < 4 && this->_spells[i] == NULL)
		this->_spells[i++] = m;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (size_t i = 0; i < INVLIMIT; ++i) {
		if (this->_spells[i] != NULL && (this->_spells[i]->getType()) == type)
			return (this->_spells[i]->clone());
	}
	return (NULL);
}