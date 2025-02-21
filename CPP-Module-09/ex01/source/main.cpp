
#include "../include/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN	rpn(argv[1]);
		rpn.startRPN();
	}
	else
		std::cerr << "Invalid number of arguments. ./RNP <operation>" << std::endl;
	return (0);
}