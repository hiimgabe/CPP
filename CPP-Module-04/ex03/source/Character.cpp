
#include "../include/Character.hpp"

Character::Character(void) : _inventory(), _name("default")
{
	std::cout << "Character default constructor called." << std::endl;
}

Character::Character(const Character &other) : ICharacter(other)
{
	std::cout << "Character copy constructor called." << std::endl;
	*this = other;
}

Character	&Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment operator called." << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

Character::~Character(void)
{
	std::cout << "Character destructor called." << std::endl;
	for (int i = 0; i < INV_SPACE; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}



std::string const & Character::getName() const { return (_name); }

void	Character::equip(AMateria* m)
{
	if (!m || m->getInUse())
	{
		std::cout << "Materia is already taken" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == 0)
		{
			_inventory[i] = m;
			m->setInUse(true);
			std::cout << "Equiped materia " << m->getType() << " at index: " << i << std::endl;
			return ;
		}
	}
	MateriaCleaner::gatherMateria(m);
}

void	Character::unequip(int idx)
{
	if (idx >= INV_SPACE || idx < 0)
	{
		std::cout << "Out of index range" << std::endl;
		return ;
	}
	else if (_inventory[idx] == NULL)
	{
		std::cout << "Inventory space is already empty" << std::endl;
	}
	MateriaCleaner::gatherMateria(_inventory[idx]);
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= INV_SPACE || idx < 0)
	{
		std::cout << "Index out of range" << std::endl;
		return ;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
}