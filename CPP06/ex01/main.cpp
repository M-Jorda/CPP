#include <iostream>

#include "Serializer.hpp"

int	main(void)
{
	Data d;
	d.name = "Hello World!";

	std::cout << "Original address : " << &d << std::endl;
	std::cout << "Original data    : " << d.name << std::endl;

	uintptr_t	raw = Serializer::serialize(&d);
	Data		*res = Serializer::deserialize(raw);

	std::cout << "Deserialized addr: " << res << std::endl;
	std::cout << "Deserialized data: " << res->name << std::endl;
	std::cout << "Addresses match  : " << (&d == res ? "yes" : "no") << std::endl;
	return (0);
}
