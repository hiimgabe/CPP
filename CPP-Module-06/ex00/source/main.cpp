
#include "../include/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Wrong number of arguments. ./static_cast <to_convert>" << std::endl, 1);
	std::string	value = argv[1];

	try
	{
		ScalarConverter::convert(value);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	return (0);
}