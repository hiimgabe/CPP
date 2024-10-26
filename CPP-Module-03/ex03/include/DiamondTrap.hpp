
#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap(void);

		DiamondTrap(std::string name);
		std::string	getName(void) const;
		void	attack(const std::string &target);
		void	whoAmI(void);

	private:
		std::string	_name;
};

std::ostream &operator<<(std::ostream &ofs, const DiamondTrap &trap);

#endif