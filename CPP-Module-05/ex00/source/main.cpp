
#include "../include/Bureaucrat.hpp"

void	normalBureaucrat()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob;

		bob.demote();
		std::cout << bob;

		bob.promote();
		std::cout << bob;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	gradeTooHigh()
{
	try
	{
		Bureaucrat	bob("Bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	gradeTooLow()
{
	try
	{
		Bureaucrat	bob("Bob", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	promotion()
{
	try
	{
		Bureaucrat	bob("Bob", 1);
		bob.promote(); 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	demotion()
{
	try
	{
		Bureaucrat	bob("Bob", 150);
		bob.demote(); 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	normalBureaucrat();
	gradeTooHigh();
	gradeTooLow();
	promotion();
	demotion();
	return(0);
}