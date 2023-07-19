#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon{
	public:
		Weapon(const std::string& type);
		Weapon(void);
		~Weapon(void);
		void		setType(const std::string& type);
		std::string	getType(void) const;
	private:
		std::string _type;
};

#endif