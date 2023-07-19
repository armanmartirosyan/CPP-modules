#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB {
	public:
		HumanB(void);
		HumanB(const std::string& name);
		~HumanB(void);
		void		setWeapon(Weapon& weapon);
		void		setName(const std::string& name);
		std::string	getName(void) const;
		std::string	getWeapon(void) const;
		void	attack(void);
	private:
		Weapon 		*_weapon;
		std::string	_name;
};

#endif