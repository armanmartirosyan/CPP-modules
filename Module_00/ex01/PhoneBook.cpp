#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_count = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::setIndex(int index) {
	this->_index = index;
	return;
}

void	PhoneBook::setCount(int count) {
	this->_count = count;
	return;
}


int	PhoneBook::getCount(void) {
	return (this->_count);
}

int PhoneBook::getIndex(void) {
	return (this->_index);
}

void	PhoneBook::setContact(void)
{
	Contact 		contact;
	static int		index;
	std::string		tmp;

	if (index >= 8)
		index = 0;
	std::cout << "Enter your first name: ";
	do { getline(std::cin, tmp); } while (!tmp.size());
	std::cout << std::endl;
	contact.setFirstName(tmp);
	std::cout << "Enter your last name: ";
	do { getline(std::cin, tmp); } while (!tmp.size());
	std::cout << std::endl;
	contact.setLastName(tmp);
	std::cout << "Enter your nick name: ";
	do { getline(std::cin, tmp); } while (!tmp.size());
	std::cout << std::endl;
	contact.setNickName(tmp);
	std::cout << "Enter your phone number: ";
	do { getline(std::cin, tmp); } while (!tmp.size() || contact.setPhoneNumber(tmp));
	std::cout << std::endl;
	std::cout << "Enter your darkest secret: ";
	do { getline(std::cin, tmp);} while (!tmp.size());
	std::cout << std::endl;
	contact.setSecret(tmp);
	this->_contacts[index] = contact;
	this->_index = index++;
	if (this->_count != 8)
		this->_count++;
}

int	PhoneBook::check_input(std::string& input, int flag) {
	if (input.size() == 0) {
		std::cout << "! Empty line !" << std::endl;
		return (EXIT_FAILURE);
	}
	if (flag == 0) {
		for (int i = 0; input[i]; i++) {
			input[i] = tolower(input[i]);
		}
		if (input != "add" && input != "search" && input != "exit")
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	else if (flag == 1) {
		for (int i = 0; i < (int)input.size(); i++)
			if (!isdigit(input[i]))
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	PhoneBook::print(std::string str) {
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
	return;
}

void	PhoneBook::search(void) {
	std::string	input;
	int			num;

	std::cout << std::setw(11) << "Index|" << std::setw(11) << "Name|"
		<< std::setw(11) << "Surname|" << std::setw(11) << "Nickname|" << std::endl;
	for (int i = 0; i < this->_count; i++) {
		std::cout << std::setw(10) << i + 1 << "|";
		print(this->_contacts[i].getFirstName());
		std::cout << "|";
		print(this->_contacts[i].getLastName());
		std::cout << "|";
		print(this->_contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "Enter the contact index: ";
	do {
		std::cin >> input;
		if (!check_input(input, 1))
			break;
		std::cout << "Wrong input!" << std::endl;
	} while (true);
	if (input.size() > 2) {
		std::cout << "No contacts with this index" << std::endl;
		return ;
	}
	num = std::stoi(input);
	if ( num < 1 || num > this->_count ) {
		std::cout << "No contacts with this index" << std::endl;
		return ;
	}
	else {
		std::cout << "Name     |" << this->_contacts[num - 1].getFirstName() << std::endl;
		std::cout << "Surname  |" << this->_contacts[num - 1].getLastName() << std::endl;
		std::cout << "Nickname |" << this->_contacts[num - 1].getNickName() << std::endl;
		std::cout << "Number   |" << this->_contacts[num - 1].getPhoneNumber() << std::endl;
		std::cout << "Secret   |" << this->_contacts[num - 1].getSecret() << std::endl;
	}
}