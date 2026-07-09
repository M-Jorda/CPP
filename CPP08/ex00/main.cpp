#include "easyfind.hpp"

using std::cout;
using std::cerr;
using std::endl;

template <typename T>
static typename T::iterator	find(T &vec, int val)
{
	return (easyfind(vec, val));
}

template <typename T, typename F>
static void	runner(std::string test, T &vec, int val, F func)
{
	try
	{
		cout << "Test: " << test << endl;
		typename T::iterator it = func(vec, val);
		cout << "Value found: "<< *it << endl;
		cout << "Pos: " << std::distance(vec.begin(), it) + 1 << endl;
	}
	catch(std::exception &e)
	{
		cerr << e.what() << endl;
	}
	cout << endl;
}

int	main(void)
{
	std::vector<int> v;
	v.push_back(-42);
	v.push_back(2);
	v.push_back(5);
	v.push_back(5);
	v.push_back(42);

	std::vector<int> empty;
	std::list<int> lst;

	runner("Found", v, 42, find<std::vector<int> >);
	runner("Not found", v, 24, find<std::vector<int> >);
	runner("Empty", empty, 42, find<std::vector<int> >);
	runner("Double", v, 5, find<std::vector<int> >);
	runner("Negative", v, -42, find<std::vector<int> >);
	runner("Negative not found", v, -24, find<std::vector<int> >);
	runner("Not a vector", lst, 0, find<std::list<int> >);
}
