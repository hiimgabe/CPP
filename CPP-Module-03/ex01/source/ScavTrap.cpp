
#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : _name("Default"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ScavTrap Default Constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) 
{
	std::cout << "ScavTrap Assign Operator" << std::endl;
	if (this != &other)
	{
		_name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " Constructor" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacked "
		<< target << " and has now " << _energyPoints << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is in Gate Keeper mode" << std::endl;
}