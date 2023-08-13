#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "AMateria.hpp"


class Character : public ICharacter {
	public:
		// Constructors
		Character(void);
		Character(const Character&);
		Character(const std::string&);
		~Character(void);

		// Operations
		Character& operator=(const Character&);

		// Getters
		std::string const & getName()	const;
		AMateria&	getInv(size_t)		const;

		// Functions
		void	equip(AMateria*);
		void	unequip(int);
		void	use(int, ICharacter&);
	private:
		std::string _name;
		AMateria*	_inv[INVLIMIT];
};

#endif