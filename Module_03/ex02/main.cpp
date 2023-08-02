#include "ScavTrap.hpp"

int main (void) {
	ScavTrap Friday("F.R.I.D.A.Y.");
	ScavTrap Vision;

	Vision = Friday;
	std::cout << Vision.getName() << std::endl;
	for (std::size_t i = 0; i < 12; i++)
		Friday.attack("Vision");
	Friday.takeDamage(80);
	Friday.takeDamage(30);
	Friday.attack("Vision");
	Friday.beRepaired(15);
	Vision.beRepaired(150);
	Vision.guardGate();
	return (0);
}