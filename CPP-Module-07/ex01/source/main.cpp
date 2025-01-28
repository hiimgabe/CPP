
#include "../include/iter.hpp"

void	printInt(int n)
{
	std::cout << n << std::endl;
}

void	printDouble(double n)
{
	std::cout << n << std::endl;
}

void	printString(std::string str)
{
	std::cout << str;
}

int	main(void)
{
	int			arrayI[5] = {1, 2, 3, 4, 5};
	double		arrayD[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string	arrayStr[5] = {"Hello ", "World, ", "this ", "is ", "computer!"};

	std::cout << "iter() array of int, size 5, printInt()" << std::endl;
	iter(arrayI, 5, printInt);
	std::cout << "\niter() array of double, size 5, printDouble()" << std::endl;
	iter(arrayD, 5, printDouble);
	std::cout << "\niter() array of std::string, size 5, printString()" << std::endl;
	iter(arrayStr, 5, printString);
	return (0);
}