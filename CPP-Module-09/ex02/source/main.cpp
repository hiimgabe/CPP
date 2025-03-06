
#include "../include/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			PmergeMe	merge(argv[1]);
			
			merge.pmergeme();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Invalid number of arguments." << std::endl;

	return (0);
}