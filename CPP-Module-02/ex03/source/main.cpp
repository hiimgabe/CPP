#include "../include/Point.hpp"

int main(void) 
{
	Point a(Fixed(4), Fixed(2));
	Point b(Fixed(4), Fixed(2));
	Point c(Fixed(4), Fixed(2));
	Point p(Fixed(4), Fixed(2));

	std::cout << a.getX() << std::endl;
	std::cout << a.getY() << std::endl;
	std::cout << bsp(a, b, c, p) << std::endl;
	return (0);
}