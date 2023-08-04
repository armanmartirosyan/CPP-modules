#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap(void) {
	this->_name = "Unknown";
	this->_health = 10;
	this->_energy = 10;
	this->_attackDamage = 0;
	std::cout << "Default ClapTrap constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) {
	this->_name = rhs.getName();
	this->_health = rhs.getHealth();
	this->_energy = rhs.getEnergy();
	this->_attackDamage = rhs.getAttackDamage();
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const std::string& name) {
	if (name.empty())
		this->_name = "(empty)";
	else
		this->_name = name;
	this->_health = 10;
	this->_energy = 10;
	this->_attackDamage = 0;
	std::cout << "Constructor ClapTrap called with parametrs" << std::endl;
	return ;
}

// Operation
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	if (this == &rhs)
		return (*this);
	this->_name = rhs.getName();
	this->_health = rhs.getHealth();
	this->_energy = rhs.getEnergy();
	this->_attackDamage = rhs.getAttackDamage();
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called" << std::endl;
	return ;
}

// Getters
std::string ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHealth(void) const {
	return (this->_health);
}

unsigned int	ClapTrap::getEnergy(void) const {
	return (this->_energy);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

// Setters
void	ClapTrap::setName(const std::string& name) {
	if (name.empty())
		this->_name = "(empty)";
	else
		this->_name = name;
	return ;
}

void	ClapTrap::setHealth(const unsigned int& health) {
	this->_health = health;
	return ;
}

void	ClapTrap::setEnergy(const unsigned int& energy) {
	this->_energy = energy;
	return;
}

void	ClapTrap::setAttackDamage(const unsigned int& attackDamage) {
	this->_attackDamage = attackDamage;
	return ;
}

// Functions
void	ClapTrap::attack(const std::string& target) {
	if (this->getHealth() <= 0) {
		std::cout << "ClapTrap " << this->getName() << " is dead!" << std::endl;
		return ;
	}
	if (this->getEnergy() == 0) {
		std::cout << "ClapTrap " << this->getName() << " has no energy to attack!" << std::endl;
		return ;
	}
	this->setEnergy(this->getEnergy() - 1);
	std::cout << "ClapTrap " << this->getName() <<  " attacks " << target;
	std::cout << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= this->getHealth()) {
		this->setHealth(0);
		std::cout << "ClapTrap " << this->getName() <<  " died." << std::endl;
		return ;
	}
	this->setHealth(this->getHealth() - amount);
	std::cout << "ClapTrap " << this->getName() <<  " take ";
	std::cout << amount << " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->getHealth() <= 0) {
		std::cout << "ClapTrap " << this->getName() << " is dead!" << std::endl;
		return ;
	}
	if (this->getEnergy() - 1 <= 0) {
		std::cout << "ClapTrap " << this->getName();
		std::cout <<  " has no energy to repair." << std::endl;
		return ;
	}
	this->setEnergy(this->getEnergy() - 1);
	this->setHealth(this->getHealth() + (int)amount);
	std::cout << "ClapTrap " << this->getName() <<  " repaired himself ";
	std::cout << amount << " points of health! ";
	std::cout << "Now he has " << this->getHealth() << " amount of health." << std::endl;
	return ;
}

void ClapTrap::printParams(void) const {
    std::cout << this->_name <<": hitPoints(" << this->_health << ") : energyPoints("
    << this->_energy<<") : attackDamage(" <<this->_attackDamage << ")" << std::endl;
	return ;
}