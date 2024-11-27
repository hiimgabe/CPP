
#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "MateriaCleaner.hpp"

#define MAX_MATERIAS 4

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource &operator=(const MateriaSource& other);
		~MateriaSource(void);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

		void displaySource(void);
	private:
		AMateria*	_inv[MAX_MATERIAS];
};

#endif