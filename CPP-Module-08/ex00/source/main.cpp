#include "../include/EasyFind.hpp"

int	main(void)
{
	std::vector<int>	intVector;
	for (int i = 0; i < 6; i++)
	{
		intVector.push_back(i);
		std::cout << "intVector[" << i << "] : " << intVector[i] << std::endl;
	}

	std::cout << "\n==== Testing ===\n" << std::endl;
	try
	{
		for (int i = 0; i <= 6; i++)
			std::cout << find(intVector, i) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
	return (0);
}