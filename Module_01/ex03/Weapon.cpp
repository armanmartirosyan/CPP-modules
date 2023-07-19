#include "Weapon.hpp"

Weapon::Weapon(void){ }

Weapon::Weapon(const std::string& type){
	this->_type = type;
	return ;
}

Weapon::~Weapon(void){ }

void	Weapon::setType(const std::string& type){
	this->_type = type;
	return ;
}

std::string	Weapon::getType(void) const{
	return (this->_type);
}