#include <iostream>

#include "Serializer.hpp"

int	main(void)
{
	Data d;
	d.name = "Hello World!";

	uintptr_t	ptr = Serializer::serialize(&d);
	Data	*res = Serializer::deserialize(ptr);
	std::cout << res << std::endl;
	std::cout << &d << std::endl;
}
