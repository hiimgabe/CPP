
#include "../include/Serializer.hpp"

Serializer::Serializer(void) { LOG("Serializer Default Constructor called."); }

Serializer::Serializer(const Serializer &other)
{
	LOG("Serializer Copy Constructor called");
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	LOG("Serializer Copy Constructor called");
	(void)other;
	return (*this);
}

Serializer::~Serializer(void) { LOG("Serializer Default Destructor called."); }

uintptr_t	Serializer::serialize(Data* ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

Data	*Serializer::deserialize(uintptr_t raw) { return (reinterpret_cast<Data*>(raw)); }