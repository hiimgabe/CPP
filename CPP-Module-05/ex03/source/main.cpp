
#include "../include/Intern.hpp"

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

int	main(void)
{
	clearScreen();
	Intern	veryImportantIntern;
	AForm*	formCorrect[3];
	AForm*	formError;

	std::cout << "\n=== Correct forms creation ===\n" << std::endl;
	try
	{
		formCorrect[0] = veryImportantIntern.makeForm("shrubbery form", "Home");
		formCorrect[1] = veryImportantIntern.makeForm("robotomy form", "Neil");
		formCorrect[2] = veryImportantIntern.makeForm("presidential form", "Bob");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n=== Incorrect forms creation ===\n" << std::endl;
	try
	{
		formError = veryImportantIntern.makeForm("unkown form", "Bob");
		(void)formError;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	(void)formCorrect;
	for (int i = 0; i < 3; i++)
		delete formCorrect[i];
	return(0);
}