
#include "../include/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Wrong number of arguments. ./static_cast <to_convert>" << std::endl, 1);
	ScalarConverter::convert(argv[1]);

	return (0);
}