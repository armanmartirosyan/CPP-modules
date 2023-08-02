#include "ClapTrap.hpp"

// Constructors

ClapTrap::ClapTrap(void) {
	this->_health = 10;
	this->_energy = 10;
	this->_attackDamage = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) {
	this->_name = rhs.getName();
	this->_health = rhs.getHealth();
	this->_energy = rhs.getEnergy();
	this->_attackDamage = rhs.getAttackDamage();
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "Constructor with called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Getters
std::string ClapTrap::getName(void) const {
	return (this->_name);
}

int	ClapTrap::getHealth(void) const {
	return (this->_health);
}

int	ClapTrap::getEnergy(void) const {
	return (this->_energy);
}

int	ClapTrap::getAttackDamage(void) const {
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
	if (this->getHealth() - (int)amount <= 0) {
		std::cout << "ClapTrap " << this->getName() <<  " died." << std::endl;
		return ;
	}
	this->setHealth(this->getHealth() - amount);
	std::cout << "ClapTrap " << this->getName() <<  " take ";
	std::cout << amount << " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
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