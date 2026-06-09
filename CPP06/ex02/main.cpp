#include "Base.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	Base *ba = generate();
	identify(ba);

}