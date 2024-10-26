

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default Constructor" << std::endl;
	_name = "";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	ClapTrap::_name = _name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap Copy Constructor" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap Assign Operator" << std::endl;
	if (this != &other)
	{
		_name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " Destructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	ClapTrap::_name = name + "_clap_name";
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Who am I? I am " << _name << std::endl;
	std::cout << "What's my ClapTrap name? It's " << ClapTrap::getName() << std::endl;
}

std::string	DiamondTrap::getName(void) const { return (_name); }

std::ostream &operator<<(std::ostream &ofs, const DiamondTrap &trap)
{
	std::cout << "Name		: " << trap.getName() << std::endl;
	std::cout << "Hit Points	: " << trap.getHitPoints() << std::endl;
	std::cout << "Energy Points	: " << trap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage	: " << trap.getAttackDamage() << std::endl;
	return (ofs);
}