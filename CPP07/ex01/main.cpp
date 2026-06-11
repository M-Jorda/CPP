#include "iter.hpp"
#include <string>

static void	increment(int &n)
{
	n++;
}

static void	printInt(const int &n)
{
	std::cout << n << " ";
}

static void	printStr(const std::string &s)
{
	std::cout << s << " ";
}

int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5};

	std::cout << "Before: ";
	iter(arr, 5, printInt);
	std::cout << std::endl;

	iter(arr, 5, increment);
	std::cout << "After increment: ";
	iter(arr, 5, printInt);
	std::cout << std::endl;

	std::string strs[] = {"hello", "world", "42"};
	std::cout << "Strings: ";
	iter(strs, 3, printStr);
	std::cout << std::endl;

	return (0);
}
