#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		Contact	setContact(void);
		void	setIndex(int index);
		void	setCount(int count);
		void	search(void);
		int		getIndex(void);
		int		getCount(void);
		int		check_input(std::string &input, int flag);
		void	print(std::string str);
	private:
		int		_index;
		int		_count;
		Contact	_contacts[8];
};

#endif