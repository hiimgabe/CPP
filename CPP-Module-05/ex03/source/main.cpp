
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
	AForm*	form;

	form = veryImportantIntern.makeForm("shrubbery form", "Home");
	// TEST TEST TEST TEST
	(void)form;
	return(0);
}