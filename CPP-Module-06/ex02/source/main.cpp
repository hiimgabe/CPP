
#include "../include/Base.hpp"

int	main(void)
{
	Base	*randomBase = generate();
	Base	*wrongBase = new Base();

	identify(wrongBase);
	identify(*wrongBase);
	identify(randomBase);
	identify(*randomBase);
	delete(wrongBase);
	delete(randomBase);
	return (0);
}