
#include "../include/Array.hpp"

int	main(void)
{
	Array<int>	test(5);

	{
		Array<int>	copy(5);

		std::cout << copy.size() << std::endl;
		copy = test;
		std::cout << copy.size() << std::endl;
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << "copy[" << i << "] : " << copy[i] << std::endl;
	}


		for (unsigned int i = 0; i < test.size(); i++)
			std::cout << "test[" << i << "] : " << test[i] << std::endl;

	//try
	//{
	//	std::cout << "Array size is: " << test.size() << std::endl;
	//	for (unsigned int i = 0; i < test.size(); i++)
	//		std::cout << "test[" << i << "] : " << test[i] << std::endl;
	//}
	//catch(const std::exception &e)
	//{
	//	std::cerr << e.what() << std::endl;
	//}
	//try
	//{
	//	std::cout << test[test.size() + 1] << std::endl;
	//}
	//catch(const std::exception &e)
	//{
	//	std::cerr << e.what() << std::endl;
	//}
	return (0);
}