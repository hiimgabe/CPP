
#ifndef ICE_H
#define	ICE_H

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice(void);

		AMateria* clone(void) const;
		void	use(ICharacter& target);
};

#endif