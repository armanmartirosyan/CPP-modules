#include "HumanA.hpp"

HumanA::HumanA(void) { }

HumanA::HumanA(const std::string& name, Weapon& weapon){
	this->setName(name);
	this->setWeapon(weapon);
}

HumanA::~HumanA(void) { }

void	HumanA::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
	return ;
}

void	HumanA::setName(const std::string& name){
	this->_name = name;
	return ;
}

std::string	HumanA::getName(void) const {
	return (this->_name);
}

std::string HumanA::getWeapon(void) const {
	return (this->_weapon->getType());
}

void HumanA::attack(void){
	std::cout << this->getName() << " attacks with their" << this->getWeapon() << std::endl;
}