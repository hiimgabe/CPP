
#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base::~Base(void) {}

Base*	generate(void)
{
	std::srand(std::time(0));
	int	random = std::rand() % 3;
	
	switch(random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			exit(1);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified Base -> A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified Base -> B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified Base -> C" << std::endl;
	else
		std::cout << "Couldn't identify Base" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified Base -> A" << std::endl;
	}
	catch(std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "Identified Base -> B" << std::endl;
		}
		catch(std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "Identified Base -> C" << std::endl;
			}
			catch(std::exception &e)
			{
				std::cerr << "Couldn't identify base." << std::endl;
			}
		}
	}
}
