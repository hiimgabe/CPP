#include "../include/Point.hpp"

int main(void) 
{
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(5), Fixed(0));
	Point c(Fixed(0), Fixed(5));
	Point p(Fixed(2), Fixed(0));

	std::cout << std::boolalpha <<  bsp(a, b, c, p) << std::endl;
	return (0);
}