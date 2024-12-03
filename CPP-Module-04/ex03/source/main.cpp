
#include "../include/AMateria.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"


/*
	"É p'ra amanhã
	Bem podias fazer hoje" - not today tho, finishing tests tomorrow
*/
//void	deepCopySource(void)
//{
//	MateriaSource*	original = new MateriaSource();
//	MateriaSource*	copy = new MateriaSource();
//
//	for (int i = 0; i < INV_SPACE; i++)
//		original->learnMateria(new Ice());
//	
//}

void	deepCopyCharacter(void)
{
	Character*	michael = new Character("Michael");
	Character*	toby = new Character("Toby");
	MateriaSource*	source = new MateriaSource();

	source->learnMateria(new Ice());
	for (int i = 0; i < INV_SPACE; i++)
		michael->equip(source->createMateria("ice"));
	std::cout << "Michael:" << std::endl;
	michael->getInv();
	std::cout << "Toby before:" << std::endl;
	toby->getInv();
	std::cout << "Tody after:" << std::endl;
	*toby = *michael;
	toby->getInv();
	delete michael;
	delete toby;
	delete source;
}

void	outOfBoundsCharacter(void)
{
	Character*	michael = new Character("Michael");
	Character*	toby = new Character("Toby");
	MateriaSource*	source = new MateriaSource();

	source->learnMateria(new Ice());
	source->learnMateria(new Cure());

	for (int i = 0; i < 8; i++)
	{
		michael->equip(source->createMateria("ice"));
		michael->use(i, *toby);
	}
	for (int i = 0; i < INV_SPACE; i++)
		michael->unequip(i);
	delete michael;
	delete toby;
	delete source;
}

void	outOfBoundsMateriaSource(void)
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

void	subjectTest(void)
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
	//outOfBoundsCharacter();
	//deepCopyCharacter();

	AMateria* mat;
	Character* bob = new Character("bob");
	MateriaSource* source = new MateriaSource();

	source->learnMateria(new Ice());
	mat = source->createMateria("ice");
	bob->equip(mat);

	bob->getInv();

	delete bob;
	delete source;
}