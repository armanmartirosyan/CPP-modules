#include "Zombie.hpp"

int main(void){
	Zombie *zFrank = newZombie("(Heap)Frank");

	zFrank->announce();
	delete zFrank;
	randomChump("(stack)Ferdinand");
	return (0);
}