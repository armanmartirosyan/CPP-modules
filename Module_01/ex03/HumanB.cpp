#include "HumanB.hpp"

HumanB::HumanB(void) { }

HumanB::HumanB(const std::string& name){
	this->setName(name);
}

HumanB::~HumanB(void) { }

void	HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
	return ;
}

void	HumanB::setName(const std::string& name){
	this->_name = name;
	return ;
}

std::string	HumanB::getName(void) const {
	return (this->_name);
}

std::string HumanB::getWeapon(void) const {
	return (this->_weapon->getType());
}

void HumanB::attack(void){
	std::cout << this->getName() << " attacks with their" << this->getWeapon() << std::endl;
}