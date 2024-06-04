#include <iostream>
#include <cstdlib>

int	main(int argc, char **argv)
{
	int	i = 1;
	int	j = 0;

	if (argc > 1)
	{
		while (argv[i] != 0)
		{
			j = 0;
			while (argv[i][j] != 0)
			{
				std::cout << (char)toupper(argv[i][j]);
				j++;
			}
			i++;
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (EXIT_SUCCESS);
}