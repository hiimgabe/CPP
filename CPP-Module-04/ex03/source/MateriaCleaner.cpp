
#include "../include/MateriaCleaner.hpp"

MateriaCleaner::MateriaCleaner(void) : _materiaList()
{
	std::cout << "MateriaCleaner default constructor called." << std::endl;
}

MateriaCleaner::~MateriaCleaner(void)
{
	std::cout << "MateriaCleaner destructor called" << std::endl;
	cleanMaterias();
}

/**
 * @brief Singleton accessor for the MateriaCleaner instance.
 * 
 * This function returns a reference to the single instance of the MateriaCleaner
 * class. The instance is created the first time this function is called and 
 * will be reused for all subsequent calls.
 * 
 * @return MateriaCleaner& Reference to the singleton instance of MateriaCleaner.
 */
MateriaCleaner& MateriaCleaner::getInstance(void)
{
	static MateriaCleaner	instance;

	return(instance);
}

/**
 * @brief Adds a materia to the cleanup list.
 * 
 * This function attempts to add a given materia to the cleanup list. If the materia is currently in use,
 * it will print a message indicating that the materia cannot be cleaned up. Otherwise, it will print a 
 * message indicating the type of the materia being cleaned up and add it to the internal list.
 * 
 * @param materia A pointer to the AMateria object to be added to the cleanup list.
 */
void MateriaCleaner::pushMateria(AMateria* materia)
{
	if (materia->getInUse())
	{
		std::cout << "Can't cleanup a materia that is being used : " << materia->getType() << std::endl;
	}
	std::cout << "Cleaning up " << materia->getType() << std::endl;
	MateriaList* new_node = new MateriaList;
	new_node->materia = materia;
	new_node->next = _materiaList;
	_materiaList = new_node;
}

void MateriaCleaner::cleanMaterias(void)
{
	std::cout << "Cleaning materias" << std::endl;
	MateriaList*	tmp;

	while (_materiaList)
	{
		tmp = _materiaList;
		_materiaList = _materiaList->next;
		delete tmp->materia;
		delete tmp;
	}
}

void MateriaCleaner::gatherMateria(AMateria* materia)
{
	getInstance().pushMateria(materia);
}

void MateriaCleaner::showListI(void)
{
	MateriaList*	current = _materiaList;

	while (current)
	{
		std::cout << _materiaList->materia->getType() << std::endl;
		current = current->next;
	}
}

void MateriaCleaner::showList(void)
{
	std::cout << "MateriaCleaner list of cleaned materias: " << std::endl;
	getInstance().showListI();
}