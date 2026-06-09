#include "ScalarConverter.hpp"

int main(void)
{
	std::string tests[] = {
		"'a'",
		"0",
		"42",
		"42.0f",
		"42.0",
		"nan",
		"nanf",
		"+inf",
		"-inff",
		"999999999999999",
		"abc"
	};

	int size = sizeof(tests) / sizeof(tests[0]);
	for (int i = 0; i < size; i++)
	{
		std::cout << "--- Input: " << tests[i] << " ---" << std::endl;
		ScalarConverter::convert(tests[i]);
		std::cout << std::endl;
	}
	return (0);
}