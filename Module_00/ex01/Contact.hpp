#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	public:
		Contact(void);
		~Contact(void);
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickName(std::string nickName);
		int  setPhoneNumber(std::string phoneNumber);
		void setSecret(std::string secret);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getPhoneNumber(void);
		std::string getSecret(void);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string _phoneNumber;
		std::string _secret;
};

#endif