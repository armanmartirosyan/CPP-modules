#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA {
	public:
		HumanA(void);
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA(void);
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