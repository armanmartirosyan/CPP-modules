#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->_index = 0;
	this->_count = 0;
}

PhoneBook::~PhoneBook(void){}

void	PhoneBook::setIndex(int index){
	this->_index = index;
	return ;
}

void	PhoneBook::setCount(int count){
	this->_count = count;
	return ;
}


int	PhoneBook::getCount(void){
	return (this->_count);
}

int PhoneBook::getIndex(void){
	return (this->_index);
}

Contact	PhoneBook::setContact(void)
{
	Contact 		contact;
	static int		index;
	std::string		tmp;

	if (index >= 8)
		index = 0;
	std::cout << "Enter your first name: ";
	do {std::cin >> tmp;} while (!tmp.size());
	std::cout <<std::endl;
		contact.setFirstName(tmp);
	std::cout << "Enter your last name: ";
	do {std::cin >> tmp;} while (!tmp.size());
	std::cout <<std::endl;
		contact.setLastName(tmp);
	std::cout << "Enter your nick name: ";
	do {std::cin >> tmp;} while (!tmp.size());
	std::cout <<std::endl;
		contact.setNickName(tmp);
	std::cout << "Enter your phone number: ";
	do {std::cin >> tmp;} while (!tmp.size() || contact.setPhoneNumber(tmp));
	std::cout <<std::endl;
	std::cout << "Enter your darkest secret: ";
	do {std::cin >> tmp;} while (!tmp.size());
	std::cout <<std::endl;
		contact.setSecret(tmp);
	this->_index = index++;
	return (contact);
}

int	PhoneBook::check_input(std::string &input){
	for (int i = 0; input[i]; i++){
			input[i] = tolower(input[i]);
		}
		if (input != "add" && input != "search" && input != "exit")
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
}

void	PhoneBook::search(void){
	std::string	input;

	std::cout << "how do you like to search contact? ";
	do {
		std::cout << std::endl << "Index | Name | Surname | Nickname" << std::endl;
		std::cin >> input;
	} while (!input.size());

}