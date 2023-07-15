#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void) const;
		void	setName(const std::string name);
	private:
		std::string _name;
};

Zombie*    zombieHorde(int N, std::string name);

#endif