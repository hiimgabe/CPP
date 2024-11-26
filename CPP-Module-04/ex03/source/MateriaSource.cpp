
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


/*
	FIX THIS, should be a deep copy
*/
MateriaSource &MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource operator constructor called" << std::endl;
	if (this != &other)
		*this = other;
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
	if (!m || m->getInUse())
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