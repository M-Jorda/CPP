#include "ScalarConverter.hpp"

int main(void)
{
	char *end;
	double d = std::strtod("999999999999999", &end);
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	return (0);
}