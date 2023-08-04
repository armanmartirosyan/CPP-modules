#pragma once 
#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	public:
		// Constructors
		DiamondTrap(void);
		DiamondTrap(const std::string&);
		DiamondTrap(const DiamondTrap&);
		~DiamondTrap(void);

		// Operations
		DiamondTrap& operator= (const DiamondTrap&);
		// Functions
		using	ScavTrap::attack;
		void	whoAmI(void);
	private:
		std::string	_name;
		using		FragTrap::_health; // 100
		using		ScavTrap::_energy; // 50
		using		FragTrap::_attackDamage; // 30

};

#endif