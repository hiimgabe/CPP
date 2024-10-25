
#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "../include/ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();
		ScavTrap(std::string name);
		void	attack(const std::string &target);
		void	guardGate();
};

#endif