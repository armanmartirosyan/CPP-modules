#pragma once 
#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
	// Constructors
		FragTrap(void);
		FragTrap(const FragTrap&);
		FragTrap(const std::string&);
		~FragTrap(void);
	
	// Operations
		FragTrap& operator=(const FragTrap&);

	// Functions
		void highFivesGuys(void);
};

#endif