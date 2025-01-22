
#ifndef	SERIALIZER_HPP
#define	SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

#ifdef DEBUG
#define LOG(str) std::cout << str << std::endl;
#else
#define LOG(str)
#endif

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer(void);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data	*deserialize(uintptr_t raw);
};

#endif