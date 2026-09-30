#include "BitcoinExchange.hpp"

using std::cout;
using std::cerr;
using std::endl;

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (BitcoinExchange::InvFile());
		BitcoinExchange btc("data.csv");
		std::ifstream	file(argv[1]);
		if (!file.is_open())
			throw (BitcoinExchange::InvFile());

		std::string	line;
		bool		first = true;
		cout << std::setprecision(10);

		while (std::getline(file, line))
		{
			if (first)
			{
				first = false;
				if (line == "date | value")
					continue;
			}
			try
			{
				size_t		pos = line.find(" | ");
				if (pos == std::string::npos)
					throw (BitcoinExchange::InvDate(line));

				std::string	date = line.substr(0, pos);
				std::string val = line.substr(pos + 3);
				if (!BitcoinExchange::isValidValue(val))
					throw (BitcoinExchange::InvDate(line));
				double		value = std::atof(val.c_str());
				if (value == 0)
					value = 0;
				
				if (!BitcoinExchange::isValidDate(date))
					throw (BitcoinExchange::InvDate(line));
				BitcoinExchange::checkValue(value);
				double rate = btc.getRate(date);
				cout << date << " => " << value << " = " << (value * rate) << endl;
			}
			catch(const std::exception& e)
			{
				cerr << e.what() << '\n';
			}
		}
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << '\n';
		return (1);
	}
}
