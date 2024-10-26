

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a;
	ClapTrap	b("b");

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	a.attack("Default");
	b.takeDamage(a.getAttackDamage());
	b.attack("a");
	a.takeDamage(b.getAttackDamage());
	a.beRepaired(100);


	std::cout << a << std::endl;
	std::cout << b << std::endl;
	return (0);
}