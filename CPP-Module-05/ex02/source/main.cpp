
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int	main(void)
{
	AForm *shrubb = new Shrubbery("HOLYMOLY");
	Bureaucrat	bur("Bob", 137);

	bur.executeForm(*shrubb);
	bur.signForm(*shrubb);
	bur.executeForm(*shrubb);


	return(0);
}