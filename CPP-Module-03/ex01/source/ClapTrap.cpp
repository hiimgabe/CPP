#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assign operator" << std::endl;
	if (this != &other)
	{
		_name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target 
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
		std::cout << "Claptrap " << _name << " has now " << _energyPoints
		<< " points of energy" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " lacks energy/hitpoints to attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " was damaged by " << amount << " and has now "
		<< _hitPoints << " hit points left" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " already died, no use damaging further." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " healed by " << amount << " and has now "
		<< _hitPoints << " hitpoints" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " lacks energy/hitpoints to be repaired." << std::endl;
}

std::string	ClapTrap::getName(void) const { return (_name); }

int	ClapTrap::getHitPoints(void) const { return (_hitPoints); }

int	ClapTrap::getEnergyPoints(void) const { return (_energyPoints); }

int	ClapTrap::getAttackDamage(void) const { return (_attackDamage); }

std::ostream &operator<<(std::ostream &ofs, const ClapTrap &trap)
{
	std::cout << "Name		: " << trap.getName() << std::endl;
	std::cout << "Hit Points	: " << trap.getHitPoints() << std::endl;
	std::cout << "Energy Points	: " << trap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage	: " << trap.getAttackDamage() << std::endl;
	return (ofs);
}