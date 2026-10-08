#include "PmergeMe.hpp"

#include <cctype>
#include <cstdlib>
#include <cerrno>

using	std::cout;
using	std::cerr;
using	std::endl;

static bool	isValidNumber(const std::string &word)
{
	if (word.size() == 0)
		return (false);
	for (size_t j = 0; j < word.size(); j++)
	{
		if (j == 0 && word[j] == '+')
		{
			j++;
			if (!word[j])
				return (false);
		}
		if (!std::isdigit(static_cast<unsigned char>(word[j])))
			return (false);
	}
	return (true);
}

static std::vector<std::string>	validate(int argc, char **argv)
{
	std::vector<std::string>	values;

	if (argc < 2)
		throw PmergeMe::UsageError();
	
	for (int i = 1; i < argc; i++)
	{
		std::istringstream	in(argv[i]);
		std::string			word;
		long				num;

		while (in >> word)
		{
			std::ostringstream	out;
			if (!isValidNumber(word))
				throw PmergeMe::InputError("invalid number \"" + word +  "\"");
			errno = 0;
			num = std::strtol(word.c_str(), NULL, 10);
			if (errno == ERANGE)
				throw PmergeMe::InputError("out of range \"" + word +  "\"");
			if (num <= 0)
				throw PmergeMe::InputError("not a positive integer \"" + word +  "\"");
			out << num;
			values.push_back(out.str());
		}
	}
	if (values.size() == 0)
		throw PmergeMe::UsageError();
	return (values);
}

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe	merge(validate(argc, argv));
		merge.vectorSort();
		merge.dequeSort();
		merge.printInfo();
	}
	catch(const PmergeMe::UsageError &e)
	{
		cerr << "Error: " << e.what() << endl;
		return (2);
	}
	catch(const PmergeMe::InputError &e)
	{
		cerr << "Error: " << e.what() << endl;
		return (1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << endl;
		return (1);
	}
}
