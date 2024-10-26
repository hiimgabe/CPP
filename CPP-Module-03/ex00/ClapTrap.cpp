

#include "ClapTrap.hpp"

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
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " Destructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructed" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target 
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		std::cout << "Claptrap " << this->_name << " has now " << this->_energyPoints
		<< " points of energy" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " lacks energy/hitpoints to attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " was damaged by " << amount << " and has now "
		<< this->_hitPoints << " hit points left" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " already died, no use damaging further." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " healed by " << amount << " and has now "
		<< this->_hitPoints << " hitpoints" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " lacks energy/hitpoints to be repaired." << std::endl;
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