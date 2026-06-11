#include "Base.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	Base *ba = generate();
	std::cout << "By pointer: ";
	identify(ba);
	std::cout << "By reference: ";
	identify(*ba);
	delete ba;
	return (0);
}
