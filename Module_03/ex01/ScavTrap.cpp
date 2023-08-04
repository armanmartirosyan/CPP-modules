#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(void){
	this->setHealth(100);
	this->setEnergy(100);
	this->setAttackDamage(30);
	std::cout << "Default ScavTrap constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap::ClapTrap() {
	this->_name = rhs.getName();
	this->_health = rhs.getHealth();
	this->_energy = rhs.getEnergy();
	this->_attackDamage = rhs.getAttackDamage();
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const std::string& name) {
	if (name.empty())
		this->_name = "(empty)";
	else
		this->_name = name;
	this->setHealth(100);
	this->setEnergy(100);
	this->setAttackDamage(30);
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

// Functions
void	ScavTrap::attack(const std::string& target) {
	if (this->getHealth() <= 0) {
		std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
		return ;
	}
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