#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap (void) {
	this->setName("Unknown");
	this->setHealth(100);
	this->setEnergy(100);
	this->setAttackDamage(30);
	std::cout << "Default FragTrap constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap (const FragTrap& rhs) : ClapTrap::ClapTrap() {
	this->setName(rhs.getName());
	this->setHealth(rhs.getHealth());
	this->setEnergy(rhs.getEnergy());
	this->setAttackDamage(rhs.getAttackDamage());
	std::cout << "Copy FragTrap constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap (const std::string& name) {
	if (name.empty())
		this->setName("(empty)");
	else
		this->setName(name);
	this->setHealth(100);
	this->setEnergy(100);
	this->setAttackDamage(30);
	std::cout << "Constructor FragTrap called with parametrs" << std::endl;
	return ;
}

// Operation
FragTrap& FragTrap::operator= (const FragTrap& rhs) {
	if (this == &rhs)
		return (*this);
	this->setName(rhs.getName());
	this->setHealth(rhs.getHealth());
	this->setEnergy(rhs.getEnergy());
	this->setAttackDamage(rhs.getAttackDamage());
	std::cout << "Copy FragTrap assignment operator called" << std::endl;
	return (*this);
}

// Destructor
FragTrap::~FragTrap(void) {
	std::cout << "Destructor FragTrap called" << std::endl;
	return ;
}

// Functions
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getName() << " high fives." << std::endl;
	return ;
}