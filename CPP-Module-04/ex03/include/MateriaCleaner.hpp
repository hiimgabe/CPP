
#ifndef MATERIACLEANER_H
#define MATERIACLEANER_H

#include <iostream>
#include "AMateria.hpp"

/*
	List to keep track of unequiped Materias
*/
struct	MateriaList
{
	AMateria*		materia;
	MateriaList*	next;	
};

class MateriaCleaner
{
	private:
		MateriaCleaner(void);
		MateriaCleaner(const MateriaCleaner&);
		MateriaCleaner &operator=(const MateriaCleaner&);
		~MateriaCleaner(void);

		void pushMateria(AMateria* materia);
		void cleanMaterias(void);
		void showListI(void);

		static MateriaCleaner& getInstance(void);

		MateriaList*	_materiaList;
	public:
		static void gatherMateria(AMateria* materia);
		static void showList(void);
};

#endif