
#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _inv()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource operator constructor called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < MAX_MATERIAS; i++)
		{
			if (_inv[i])
			{
				delete _inv[i];
				_inv[i] = NULL;
			}
			if (other._inv[i])
				_inv[i] = other._inv[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (_inv[i])
			delete _inv[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m->getInUse())
	{
		std::cout << "Materia is already taken" << std::endl;
		return ;
	}
	for(int i = 0; i < MAX_MATERIAS; i++)
	{
		if (_inv[i] == NULL)
		{
			_inv[i] = m;
			m->setInUse(true);
			return ;
		}
	}
	MateriaCleaner::gatherMateria(m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (_inv[i] && _inv[i]->getType() == type)
		{
			AMateria* new_materia = _inv[i]->clone();
			new_materia->setInUse(false);
			return(new_materia);
		}
	}
	return (NULL);
}

void MateriaSource::displaySource(void)
{
	std::cout << "Current MateriaSource inventory:" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		std::cout << "At index : " << i << " " << _inv[i]->getType() << std::endl;
	}
}