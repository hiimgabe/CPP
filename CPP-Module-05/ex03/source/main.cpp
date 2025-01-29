
#include "../include/Intern.hpp"

void	clearScreen(void)
{
	std::cout << "\033c";
}

void	pressEnter(void)
{
	std::cout << "\nPress Enter to continue. . ." << std::endl;
	std::cin.get();
}

/**
 * @brief
 * 
 * This function demonstrates the creation of various forms using an Intern object.
 * It attempts to create three correct forms and one incorrect form, handling any exceptions
 * that may occur during the form creation process.
 * 
 * The correct forms created are:
 * - Shrubbery form
 * - Robotomy form
 * - Presidential form
 * 
 * The incorrect form creation attempts to create an unknown form type.
 * 
 */
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
	for (int i = 0; i < 3; i++)
		delete formCorrect[i];
	return(0);
}