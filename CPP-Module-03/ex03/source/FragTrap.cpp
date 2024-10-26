
#include "../include/FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap Default Constructor" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap Copy Constructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Assign Operator" << std::endl;
	if (this != &other)
	{
		_name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " Destructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << _name << " Constructor" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Everyone received an high five from FragTrap!" << std::endl;
}