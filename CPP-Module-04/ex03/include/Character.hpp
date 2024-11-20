
#ifndef CHARACTER_H
#define	CHARACTER_H

#include "ICharacter.hpp"

#define INV_SPACE 4

class Character : public ICharacter
{
	public:
		Character(void);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character(void);

		std::string const & getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

		AMateria*	getInv(void) const;
	private:
		std::string	_name;
		AMateria*	_inventory[INV_SPACE];
};

#endif