#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange()
{
	cout << "creation af standard BitcoinExchange" << endl;
}

BitcoinExchange::BitcoinExchange(std::string dbPath)
{
	cout << "Creation of BitcoinExchange" << endl;
	_loadDb(dbPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	cout << "Creation of a copy of BitcoinExchange" << endl;
	_rates = other._rates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		cout << "Assignation of a copy of BitcoinExchange" << endl;
		_rates = other._rates;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	cout << "Destruction of BitcoinExchange" << endl;
}

float	BitcoinExchange::getRate(std::string const &date) const
{
	std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
	if (it->first == date)
		return (it->second);
	if ((it != _rates.end() && it->first != date) || it ==_rates.end())
		return ((--it)->second);
	if (it  == _rates.begin() && it->first != date)
		throw Date404();
	return (0);
}

void	BitcoinExchange::printRates()
{
	std::map<std::string, float>::const_iterator it;

	for ((it = _rates.begin()); it != _rates.end(); it++)
		cout << it->first << " => " << it->second << endl;
}

void	BitcoinExchange::checkValue(float const &value)
{
	if (value < 0)
		throw BitcoinExchange::InvValueNeg();
	if (value > 1000)
		throw BitcoinExchange::InvValueBig();
}

static bool	validCalendarValue(std::string date)
{
	int	months[12];
	months[0] = LONG_MESS;
	months[1] = 28;
	months[2] = LONG_MESS;
	months[3] = SHORT_MESS;
	months[4] = LONG_MESS;
	months[5] = SHORT_MESS;
	months[6] = LONG_MESS;
	months[7] = LONG_MESS;
	months[8] = SHORT_MESS;
	months[9] = LONG_MESS;
	months[10] = SHORT_MESS;
	months[11] = LONG_MESS;
	
	int	Y = std::atoi(date.substr(0, 4).c_str());

	int	M = std::atoi(date.substr(5, 2).c_str());
	if (M < 1 || M > 12)
		return (false);

	int	D = std::atoi(date.substr(8, 2).c_str());

	if (M == 2)
		if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))
			months[1] = 29;

	if (D < 1 || D > months[M - 1])
		return (false);

	return (true);
}

bool		BitcoinExchange::isValidDate(std::string const &date)
{
	if (date.size() != DATE_LEN || date[4] != '-' || date[7] != '-')
	{
		cout << "ERR1" << endl;
		return (false);
	}

	for (int i = 0; i < DATE_LEN; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] == '-')
				i++;
			else
			{
				cout << "ERR2, i = " << i << endl;
				return (false);
			}
		}
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
		{
			cout << "ERR3" << endl;
			return (false);
		}
	}

	return  (validCalendarValue(date));
}

const char	*BitcoinExchange::InvFile::what() const throw()
{
	return ("Error: could not open file.");
}

BitcoinExchange::InvDate::InvDate(std::string const &line)
{
	_msg = "Error: bad input => " + line;
}

BitcoinExchange::InvDate::~InvDate() throw()
{
}

const char	*BitcoinExchange::InvDate::what() const throw()
{
	return (_msg.c_str());
};

const char	*BitcoinExchange::Date404::what() const throw()
{
	return ("Error: Could'nt find an appropriate date");
}

const char	*BitcoinExchange::InvValueNeg::what() const throw()
{
	return ("Error: not a positive number.");
};

const char	*BitcoinExchange::InvValueBig::what() const throw()
{
	return ("Error: too large a number.");
};

// static void	areValidValue(std::string date, float value, std::string line)
// {
// 	if (!BitcoinExchange::isValidDate(date))
// 		throw (BitcoinExchange::InvDate(line));
// 	if (value < 0)
// 		throw BitcoinExchange::InvValueNeg();
// 	if (value > 1000)
// 		throw BitcoinExchange::InvValueBig();
// }

// void	BitcoinExchange::parseFile(std::string name, std::string separator)
// {
// 	std::ifstream	file(name.c_str());
// 	if (!file.is_open())
// 		throw BitcoinExchange::InvFile();

// 	std::string	line;
// 	std::getline(file, line);

// 	while (std::getline(file, line))
// 	{
// 		size_t		pos = line.find(separator);
// 		std::string	date = line.substr(0, pos);
// 		float		value = std::atof(line.substr(pos + 1).c_str());

// 		if (separator == " | ")
// 		{
// 			try
// 			{
// 				cout << "test1" << endl;
// 				areValidValue(date, value, line);
// 				_rates[date] = value;
// 				getRate(date);
// 			}
// 			catch(const std::exception& e)
// 			{
// 				file.close();
// 				std::cerr << e.what() << '\n';
// 			}
// 		}
// 		else
// 			_data[date] = value;
// 		cout << "test2" << endl;
// 	}
// 	file.close();
// }

void	BitcoinExchange::_loadDb(std::string const &path)
{
	std::ifstream	file(path.c_str());
	if (!file.is_open())
		throw BitcoinExchange::InvFile();

	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		size_t		pos = line.find(",");
		std::string	date = line.substr(0, pos);
		float		value = std::atof(line.substr(pos + 1).c_str());
		_rates[date] = value;
	}
	// printRates();
	
	file.close();
}
