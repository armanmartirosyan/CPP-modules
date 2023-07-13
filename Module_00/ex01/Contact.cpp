#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void	Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
	return;
}

void	Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
	return;
}

void	Contact::setNickName(std::string nickName) {
	this->_nickName = nickName;
	return;
}

int	Contact::setPhoneNumber(std::string phoneNumber) {
	for (int i = 0; phoneNumber[i]; i++)
		if (!isdigit(phoneNumber[i])) {
			std::cout << "Only numbers!" << std::endl;
			std::cout << "Insert again: ";
			return (1);
		}
	this->_phoneNumber = phoneNumber;
	return (0);
}

void	Contact::setSecret(std::string secret) {
	this->_secret = secret;
	return;
}

std::string	Contact::getFirstName(void) {
	return (this->_firstName);
}

std::string Contact::getLastName(void) {
	return (this->_lastName);
}

std::string Contact::getNickName(void) {
	return (this->_nickName);
}

std::string Contact::getPhoneNumber(void) {
	return (this->_phoneNumber);
}

std::string Contact::getSecret(void) {
	return (this->_secret);
}