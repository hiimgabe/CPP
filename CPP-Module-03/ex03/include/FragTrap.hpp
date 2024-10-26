
#include "ClapTrap.hpp"

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap(void);

		FragTrap(std::string name);
		void	highFivesGuys(void);
};

#endif