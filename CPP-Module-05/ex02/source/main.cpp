
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int	main(void)
{
	Shrubbery	shrubb("Home");

	shrubb.setIsSigned(true);
	std::cout << shrubb;

	return(0);
}