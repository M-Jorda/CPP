#include "Span.hpp"

#define SIZE 10000

using std::cout;
using std::cerr;
using std::endl;

static void	test0()
{
	Span sp = Span(SIZE);

	sp.addNumber(rand());
	try
	{
		cout << sp.longestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}

	try
	{
		cout << sp.shortestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}
}

static void	test1(Span &sp)
{
	for (int i = 0; i < SIZE - 1; i++)
		sp.addNumber(rand());

	try
	{
		cout << sp.shortestSpan() << endl;
		cout << sp.longestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}
}

static void	test2(void)
{
	Span sp = Span(SIZE);
	test1(sp);
	try
	{
		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void	test3and5(int num)
{
	Span sp;
	int	sze;

	if (num)
	{
		sp = Span(SIZE);
		sze = SIZE + 1;
	}
	else
	{
		sp = Span(num);
		sze = num;
	}

	std::vector<int> v;

	for (int i = 0; i < sze; i++)
		v.push_back(rand());
	
	try
	{
		sp.addNumbers(v.begin(), v.end());
		cout << sp.shortestSpan() << endl;
		cout << sp.longestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void	test4()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main()
{
	srand(time(0));

	Span sp = Span(SIZE);

	cout << endl << "TEST" << endl << endl;

	cout << endl << "Test 0: not enought" << endl;
	test0();
	cout << endl << "Test 1: normal use" << endl;
	test1(sp);
	cout << endl << "Test 2: too much" << endl;
	test2();
	cout << endl << "Test 3: addNumbers too many" << endl;
	test3and5(0);
	cout << endl << "Test 4: normal 42 use" << endl;
	test4();
	cout << endl << "Test 5: addNumbers with large numbers" << endl;
	test3and5(1000000);
}