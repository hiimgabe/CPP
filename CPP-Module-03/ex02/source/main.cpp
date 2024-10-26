

#include "../include/FragTrap.hpp"

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
	FragTrap	trap1("Trap 1");
	FragTrap	trap2("Trap 2");
	FragTrap	clone = FragTrap("Clone");


	std::cout << std::endl << "===== BEGGINING STATS =====" << std::endl;
	std::cout << trap1 << std::endl;
	std::cout << trap2 << std::endl;
	std::cout << clone << std::endl;

	trap2.attack("Trap 1");
	trap1.takeDamage(trap2.getAttackDamage());
	trap1.attack("Trap 2");
	trap2.takeDamage(trap1.getAttackDamage());
	trap2.beRepaired(100);
	trap1.highFivesGuys();

	clone = trap1;

	std::cout << std::endl << "===== ENDING STATS =====" << std::endl;
	std::cout << trap1 << std::endl;
	std::cout << trap2 << std::endl;
	std::cout << clone << std::endl;
	return (0);
}