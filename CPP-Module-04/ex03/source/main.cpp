
#include "../include/AMateria.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

#define RESET "\033[0m"
#define RED "\033[38;5;196m"
#define GREEN "\033[38;5;47m"
#define YELLOW "\033[38;5;226m"

void	clearScreen(void)
{
	std::cout << "\033c";
}

void	pressEnter(void)
{
	std::cout << "\nPress Enter to continue. . ." << std::endl;
	std::cin.get();
}

void	subjectTest(void)
{
	std::cout << YELLOW << "\n=== Creating MateriaSource ===\n" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << YELLOW << "\n=== MateriaSource learns Materias ===\n" << RESET << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << YELLOW << "\n=== Creating Character ===\n" << RESET << std::endl;
	ICharacter* tommy = new Character("Tommy");
	std::cout << YELLOW << "\n=== Creating & equiping Materias ===\n" << RESET << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	tommy->equip(tmp);
	tmp = src->createMateria("cure");
	tommy->equip(tmp);
	std::cout << YELLOW << "\n=== Creating target for Tommy ===\n" << RESET << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << GREEN << "\n=== Tommy uses Materias on Bob ===\n" << RESET << std::endl;
	tommy->use(0, *bob);
	tommy->use(1, *bob);
	std::cout << std::endl;
	delete bob;
	delete tommy;
	delete src;
	pressEnter();
}

void	deepCharacterCopyTest()
{
	std::cout << YELLOW << "\n=== Creating MateriaSource & Character ===\n" << RESET << std::endl;
	IMateriaSource	*src = new MateriaSource();
	Character		*tommy = new Character("Tommy");
	Character		*copy = new Character("Copy");
	std::cout << YELLOW << "\n=== MateriaSource learns Materias ===\n" << RESET << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << YELLOW << "\n=== MateriaSource creates Materias & Character equips ===\n" << RESET << std::endl;
	AMateria	*mat;
	mat = src->createMateria("ice");
	tommy->equip(mat);
	mat = src->createMateria("cure");
	tommy->equip(mat);
	std::cout << YELLOW << "\n=== Copy before ===\n" << RESET << std::endl;
	copy->use(0, *copy);
	copy->use(1, *copy);
	*copy = *tommy;
	std::cout << GREEN << "\n=== Original ===\n" << RESET << std::endl;
	tommy->use(0, *copy);
	tommy->use(1, *copy);
	std::cout << GREEN << "\n=== Copy after ===\n" << RESET << std::endl;
	copy->use(0, *copy);
	copy->use(1, *copy);
	std::cout << std::endl;
	delete tommy;
	delete src;
	delete copy;
	pressEnter();
}

void	deepMateriaCopyTest()
{
	MateriaSource	*original = new MateriaSource();
	MateriaSource	*copy = new MateriaSource();

	original->learnMateria(new Ice());
	original->learnMateria(new Cure());
	std::cout << GREEN << "\n=== Original inventory ===\n" << RESET << std::endl;
	original->displaySource();
	std::cout << YELLOW << "\n=== Copy inventory before ===\n" << RESET << std::endl;
	copy->displaySource();
	std::cout << std::endl;
	*copy = *original;
	std::cout << GREEN << "\n=== Copy inventory after ===\n" << RESET << std::endl;
	copy->displaySource();
	std::cout << std::endl;
	delete original;
	delete copy;
	pressEnter();
}

void	cleanupLimitTest(void)
{
	IMateriaSource	*src = new MateriaSource();
	ICharacter		*tommy = new Character();

	std::cout << YELLOW << "\n=== Learning Materias ===\n" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		src->learnMateria(new Ice());
	AMateria	*mat;
	std::cout << YELLOW << "\n=== Creating & equiping Materias ===\n" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		mat = src->createMateria("ice");
		tommy->equip(mat);
	}
	std::cout << GREEN << "\n=== Cleanup list ===\n" << RESET << std::endl;
	MateriaCleaner::showList();
	std::cout << std::endl;
	delete src;
	delete tommy;
	pressEnter();
}

int	main(void)
{
	clearScreen();
	subjectTest(); // Test OK OK
	cleanupLimitTest(); // Test OK OK
	deepCharacterCopyTest(); // Test OK OK
	deepMateriaCopyTest(); // Test OK OK
}