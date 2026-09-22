#include "BitcoinExchange.hpp"

using std::cout;
using std::cerr;
using std::endl;

static int	err()
{
	cerr << "Error: could not open file" << endl;
	return (1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (err());

	try
	{
		BitcoinExchange btc("data.csv");
		std::ifstream	file(argv[1]);
		if (!file.is_open())
			return (err());

		std::string	line;
		std::getline(file, line);

		while (std::getline(file, line))
		{
			size_t		pos = line.find(",");
			std::string	date = line.substr(0, pos);
			float		value = std::atof(line.substr(pos + 1).c_str());
			try
			{
				if (!BitcoinExchange::isValidDate(date))
					throw (BitcoinExchange::InvDate(line));
				BitcoinExchange::checkValue(value);
				float rate = btc.getRate(date);
			cout << date << " => " << value << " = " << (value * rate) << endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
	}
}
