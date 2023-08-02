#include "ClapTrap.hpp"

int main (void) {
	ClapTrap Friday("F.R.I.D.A.Y.");
	ClapTrap Vision;

	Vision = Friday;
	std::cout << Vision.getName() << std::endl;
	for (std::size_t i = 0; i < 12; i++)
		Friday.attack("Vision");
	Friday.takeDamage(8);
	Friday.takeDamage(3);
	Vision.beRepaired(15);
	return (0);
}