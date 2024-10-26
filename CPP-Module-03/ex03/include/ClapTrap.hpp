#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		virtual ~ClapTrap();

		ClapTrap(std::string name);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int	getHitPoints(void) const;
		int	getEnergyPoints(void) const;
		int	getAttackDamage(void) const;

	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

std::ostream &operator<<(std::ostream &ofs, const ClapTrap &trap);

#endif