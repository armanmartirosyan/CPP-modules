#include "ScavTrap.hpp"

int main (void) {
	ScavTrap Friday("F.R.I.D.A.Y.");
	ScavTrap Vision;

	Vision = Friday;
	std::cout << Vision.getName() << std::endl;
	for (std::size_t i = 0; i < 12; i++)
		Friday.attack("Vision");
	Friday.printParams();
	Friday.takeDamage(8);
	Friday.takeDamage(3);
	Friday.printParams();
	Friday.attack("Vision");
	Friday.beRepaired(15);
	Vision.beRepaired(15);
	Vision.printParams();
	Friday.guardGate();
	return (0);
}