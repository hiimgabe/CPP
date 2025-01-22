
#include "../include/Serializer.hpp"

void	testFunc(uintptr_t data)
{
	Data *deserialized = Serializer::deserialize(data);

	std::cout << "\nDeserialing data:" << std::endl;
	std::cout << deserialized->testString << std::endl;
}

int	main(void)
{
	Data	serialize;

	serialize.testString = "Hello Serial!";

	uintptr_t serial = Serializer::serialize(&serialize);
	std::cout << "\nSerialized data:" << std::endl;
	// value stored at the memory location that serial points to.
	std::cout << *reinterpret_cast<int*>(serial) << std::endl;
	// serial memory address
	std::cout << reinterpret_cast<int*>(serial) << std::endl;
	testFunc(serial);
	return (0);
}