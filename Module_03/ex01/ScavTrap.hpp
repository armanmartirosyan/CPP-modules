#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		// Constructors
		ScavTrap(void);
		ScavTrap(const ScavTrap&);
		ScavTrap(const std::string&);
		~ScavTrap(void);
		
		// Operations
		ScavTrap& operator=(const ScavTrap&);

		// Functions
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif