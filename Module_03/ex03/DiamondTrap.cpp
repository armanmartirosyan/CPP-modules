#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(void) : ClapTrap::ClapTrap(), FragTrap::FragTrap(), ScavTrap::ScavTrap() {
	this->_name = "(Unknown)";
	std::cout << "Default DiamondTrap constructor called";
	std::cout << "Name: " << this->_name << std::endl;
	return ;
}


DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap::ClapTrap(name), FragTrap::FragTrap(name),
	ScavTrap::ScavTrap(name) {
	this->_name = name;
	std::cout << "Constructor DiamondTrap called with parametrs" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) : ClapTrap::ClapTrap(rhs), FragTrap::FragTrap(rhs),
	ScavTrap::ScavTrap(rhs) {
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
	return ;
}

// Operation
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
        FragTrap::operator=(rhs);
        ScavTrap::operator=(rhs);
        this->_name = rhs.getName();
    }
    return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap(void) {
	std::cout << "Destructor DiamondTrap called" << std::endl;
	return ;
}

// Functions
void DiamondTrap::whoAmI() {
    std::cout<< "I am " << this->_name << std::endl;
    std::cout<< "my ClapTrap name " << ClapTrap::_name<<std::endl;
	return ;
}