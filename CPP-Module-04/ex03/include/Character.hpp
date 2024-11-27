
#ifndef CHARACTER_H
#define	CHARACTER_H

#include "MateriaCleaner.hpp"
#include "ICharacter.hpp"

#define INV_SPACE 4

class Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character(void);

		std::string const & getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

		AMateria*	getInvItem(int idx);
		void	getInv(void);
	private:
		AMateria*	_inventory[INV_SPACE];
		std::string	_name;
};

#endif