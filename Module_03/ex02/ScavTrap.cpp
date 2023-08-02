#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(void) {
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) {
	this->_name = rhs.getName();
	this->_health = rhs.getHealth();
	this->_energy = rhs.getEnergy();
	this->_attackDamage = rhs.getAttackDamage();
	std::cout << "Copy ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) {
	if (name.empty())
		this->_name = "(empty)";
	else
		this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
	std::cout << "Constructor ScavTrap called with parametrs" << std::endl;
	return ;
}

// Operation
ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	if (this == &rhs)
		return (*this);
	this->_name = rhs.getName();
	this->_health = rhs.getHealth();
	this->_energy = rhs.getEnergy();
	this->_attackDamage = rhs.getAttackDamage();
	std::cout << "Copy ScavTrap assignment operator called" << std::endl;
	return (*this);
}

// Destructor
ScavTrap::~ScavTrap(void) {
	std::cout << "Destructor ScavTrap called" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->getEnergy() == 0) {
		std::cout << "ScavTrap " << this->getName() << " has no energy to attack!" << std::endl;
		return ;
	}
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "ScavTrap " << this->getName() <<  " attacks " << target;
	std::cout << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	return ;
}

void	ScavTrap::guardGate(void) {
	std::cout << "You shall not pass! ";
	std::cout << "Because ScavTrap " << this->getName() << " is gurading the gate. =)" << std::endl;
	return ;
}