

#include "../include/ScavTrap.hpp"
#include "../include/ClapTrap.hpp"

/*
	ClapTrap:
		hp	:	10
		ep	:	10
		atk	:	0
	
	ScavTrap:
		hp	:	100
		ep	:	50
		atk	:	20
*/

int	main()
{
	ScavTrap	defaultTrap;
	ScavTrap	itachi("Itachi");

	std::cout << defaultTrap << std::endl;
	std::cout << itachi << std::endl;

	itachi.attack("Default");
	defaultTrap.takeDamage(itachi.getAttackDamage());
	defaultTrap.attack("Itachi");
	itachi.takeDamage(defaultTrap.getAttackDamage());
	itachi.beRepaired(100);
	defaultTrap.guardGate();

	ScavTrap	clone = itachi;

	std::cout << defaultTrap << std::endl;
	std::cout << itachi << std::endl;
	std::cout << clone << std::endl;
	return (0);
}