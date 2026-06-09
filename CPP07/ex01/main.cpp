#include "iter.hpp"

static void	n1(int &n)
{
	n++;
}

static void print(const int &n)
{
	std::cout << n << std::endl;
}

int	main(void)
{
	int arr[] = {1, 2, 3};
	// const int arr[] = {1, 2, 3};
	std::cout << "Print" << std::endl;
	iter(arr, 3, print);
	std::cout << "n1" << std::endl;
	iter(arr, 3, n1);
	std::cout << "Print" << std::endl;
	iter(arr, 3, print);
}
