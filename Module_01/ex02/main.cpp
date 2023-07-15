#include "Zombie.hpp"

int main(void){
	Zombie* horde = zombieHorde(15, "Franks");

	for (int i = 0; i < 15; i++)
		horde[i].announce();
	delete[] horde;
	horde = NULL;
	return (0);
}