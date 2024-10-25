

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a;
	//ClapTrap b(ClapTrap("Pain"));
	//ClapTrap c = b;
	//ClapTrap d("Itachi");

	//a.attack("Itachi");
	//b.takeDamage(10);
	//b.beRepaired(1);
	//c.beRepaired(5);
	//d.takeDamage(5);
	//d.beRepaired(5);
	a.takeDamage(3);
	ClapTrap b = a;
	return 0;
}