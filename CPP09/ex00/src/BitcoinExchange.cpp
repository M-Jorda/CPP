#include "BitcoinExchange.hpp"

using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::string dbPath)
{
	_loadDb(dbPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates)
{}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

float	BitcoinExchange::getRate(std::string const &date) const
{
	std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date)
		return (it->second);
	if (it  == _rates.begin())
		throw Date404();
	return ((--it)->second);
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
		return (false);

	for (int i = 0; i < DATE_LEN; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] == '-')
				i++;
			else
				return (false);
		}
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
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
	return ("Error: Couldn't find an appropriate date");
}

const char	*BitcoinExchange::InvValueNeg::what() const throw()
{
	return ("Error: not a positive number.");
};

const char	*BitcoinExchange::InvValueBig::what() const throw()
{
	return ("Error: too large a number.");
};

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
