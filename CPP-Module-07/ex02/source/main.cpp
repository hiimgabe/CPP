
#include "../include/Array.hpp"

int	main(void)
{
	Array<int>	arr;
	Array<int>	nonEmpty(5);

	std::cout << arr.size() << std::endl;
	std::cout << nonEmpty.size() << std::endl;

	try
	{
		for (int i = 0; i < 6; i++)
			std::cout << nonEmpty[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return (0);
}