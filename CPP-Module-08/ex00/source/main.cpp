#include "../include/EasyFind.hpp"
#include <vector>

void	intTest()
{
	std::vector<int>	intVector;
	for (int i = 0; i < 6; i++)
	{
		intVector.push_back(i * 2);
		std::cout << "intVector[" << i << "] : " << intVector[i] << std::endl;
	}

	std::cout << "\n==== Testing ===\n" << std::endl;
	try
	{
		std::cout << "Checking for: 10\t" << find(intVector, 10) << std::endl;
		std::cout << "Checking for: 3\t\t" << find(intVector, 3) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	intTest();
	
	return (0);
}