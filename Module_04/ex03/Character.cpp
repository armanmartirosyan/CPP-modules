#include "Character.hpp"

// Constructors
Character::Character(void) {
	this->_name = "(Call me NoBody)";
	for (size_t i = 0; i < INVLIMIT; ++i)
		this->_inv[i] = NULL;
	return ;
}

Character::Character(const std::string& name) {
	this->_name = name;
	for (size_t i = 0; i < INVLIMIT; ++i)
		this->_inv[i] = NULL;
	return ;
}

Character::Character(const Character& rhs) {
	this->_name = rhs.getName();
	for (size_t i = 0; i < INVLIMIT; ++i)
		this->_inv[i] = &rhs.getInv(i);
	return ;
}

// Destructor
Character::~Character(void) {
	for (size_t i = 0; i < INVLIMIT; ++i) {
		if (this->_inv[i] != NULL)
			delete this->_inv[i];
	}
	return ;
}

// Operations
Character& Character::operator=(const Character& rhs) {
	if (this == &rhs)
		return (*this);
	this->_name = rhs.getName();
	for (size_t i = 0; i < INVLIMIT; ++i)
		this->_inv[i] = &rhs.getInv(i);
	return (*this);
}

// Getters
std::string const & Character::getName() const {
	return (this->_name);
}

AMateria&	Character::getInv(size_t i) const {
	return *(this->_inv[i]);
}

// Functinos
void	Character::equip(AMateria* slot) {
	static size_t	i = 0;

	if (i < 4 && this->_inv[i] == NULL)
		this->_inv[i] = slot;
	return ;
}

void	Character::unequip(int i) {
	if (i >= 0 && i < 4 && this->_inv[i] != NULL)
		this->_inv[i] = NULL;
	return ;
}

void	Character::use(int idx, ICharacter& target) {
	this->_inv[idx]->use(target);
	return ;
}