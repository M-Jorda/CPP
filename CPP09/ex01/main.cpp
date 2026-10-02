#include "RPN.hpp"
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

bool	isSpace(char *av)
{
	int	i = 0;

	while (av[i])
		if (av[i] == ' ' || av[i] == '\t')
			i++;
		else
			return (false);
	return (true);
}

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2 || isSpace(argv[1]))
			throw (RPN::UsageError());
		
		RPN rpn;
		int r = rpn.calculate(argv[1]);
		cout << r << endl;
	}
	catch(RPN::UsageError const &e)
	{
		cerr << e.what() << endl;
		return (2);
	}
	catch(RPN::ExpressionError const &e)
	{
		cerr << e.what() << endl;
		return (1);
	}
	catch(const std::exception& e)
	{
		cerr << "Error: " << e.what() << endl;
		return (1);
	}
	
	return (0);
}