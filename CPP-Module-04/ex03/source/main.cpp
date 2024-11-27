
#include "../include/AMateria.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

void	outOfBoundsMateriaSource()
{
	MateriaSource* source = new MateriaSource();
	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

	AMateria* materia;
	for (int i = 0; i < 6; i++)
	{
		materia = source->createMateria("ice");
		source->learnMateria(materia);
	}
	source->displaySource();
	MateriaCleaner::showList();

	delete source;
}

void	subjectTest()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int	main(void)
{
	//subjectTest();
	//outOfBoundsMateriaSource();
}