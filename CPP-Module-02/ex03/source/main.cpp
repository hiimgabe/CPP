#include "../include/Point.hpp"

static bool bspDEBUG(Point const a, Point const b, Point const c, Point const p)
{
	Fixed abcArea = triangleArea(a, b, c);
	Fixed pabArea = triangleArea(p, a, b);
	Fixed pbcArea = triangleArea(p, b, c);
	Fixed pcaArea = triangleArea(p, c, a);

	std::cout << "abc area  : " << abcArea << std::endl;
	std::cout << "pab area  : " << pabArea << std::endl;
	std::cout << "pbc area  : " << pbcArea << std::endl;
	std::cout << "pca area  : " << pcaArea << std::endl;
	std::cout << "sum       : " << pabArea + pbcArea + pcaArea << std::endl;
	std::cout << "sum = abc : " << std::boolalpha << ((pabArea + pbcArea + pcaArea) == abcArea) << std::endl;
	std::cout << "pab edge  : " << std::boolalpha << (pabArea == 0) << std::endl;
	std::cout << "pbc edge  : " << std::boolalpha << (pbcArea == 0) << std::endl;
	std::cout << "pca edge  : " << std::boolalpha << (pcaArea == 0) << std::endl;
	if (pabArea == 0 || pbcArea == 0 || pcaArea == 0)
		return (false);
	return ((pabArea + pbcArea + pcaArea) == abcArea);
}

static bool edgeTest(int argc)
{
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(5), Fixed(0));
	Point c(Fixed(0), Fixed(5));
	Point p(Fixed(0), Fixed(5));


	if (argc > 1)
	{
		std::cout << "=========== ET DEBUG ===========" << std::endl;
		bspDEBUG(a, b, c, p);
		std::cout << "================================" << std::endl;
	}
	return (bsp(a, b, c, p));
}

static bool floatTest(int argc)
{
	Point a(Fixed(0.0f), Fixed(0.0f));
	Point b(Fixed(5.0f), Fixed(0.0f));
	Point c(Fixed(0.0f), Fixed(5.0f));
	Point p(Fixed(2.0f), Fixed(2.0f));

	if (argc > 1)
	{
		std::cout << "=========== FT DEBUG ===========" << std::endl;
		bspDEBUG(a, b, c, p);
		std::cout << "================================" << std::endl;
	}
	return (bsp(a, b, c, p));
}

static bool intTest(int argc)
{
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(5), Fixed(0));
	Point c(Fixed(0), Fixed(5));
	Point p(Fixed(2), Fixed(2));

	if (argc > 1)
	{
		std::cout << "=========== IT DEBUG ===========" << std::endl;
		bspDEBUG(a, b, c, p);
		std::cout << "================================" << std::endl;
	}
	return (bsp(a, b, c, p));
}

int main(int argc, char **argv) 
{
	bool iT = intTest(argc);
	bool fT = floatTest(argc);
	bool eT = edgeTest(argc);

	std::cout << "intTest   : " << std::boolalpha << iT << std::endl;
	std::cout << "floatTest : " << std::boolalpha << fT << std::endl;
	std::cout << "edgeTest  : " << std::boolalpha << eT << std::endl;
	return (0);
}