#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
	public:
		Contact();
		~Contact();
		
	private:
		int		index;
		string	firstName;
		string	lastName;
		string	nickName;
}

#endif