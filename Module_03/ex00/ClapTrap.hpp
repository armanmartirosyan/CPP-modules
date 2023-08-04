#pragma once 
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	public:
		// Constructors
		ClapTrap(void);
		ClapTrap(const std::string&);
		ClapTrap(const ClapTrap&);
		~ClapTrap(void);
		
		// Operations
		ClapTrap& operator=(const ClapTrap&);

		// Functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// Getters
		std::string		getName(void)			const;
		unsigned int	getHealth(void)			const;
		unsigned int	getEnergy(void)			const;
		unsigned int	getAttackDamage(void)	const;
		void			printParams(void)		const;

		// Setters
		void	setName(const std::string&);
		void	setHealth(const unsigned int&);
		void	setEnergy(const unsigned int&);
		void	setAttackDamage(const unsigned int&);

	private:
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energy;
		unsigned int	_attackDamage;
};

#endif