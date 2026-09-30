#include "BitcoinExchange.hpp"

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

double	BitcoinExchange::getRate(std::string const &date) const
{
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date)
		return (it->second);
	if (it  == _rates.begin())
		throw Date404();
	return ((--it)->second);
}

void	BitcoinExchange::checkValue(double const &value)
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
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}

	return  (validCalendarValue(date));
}

bool	BitcoinExchange::isValidValue(std::string const &s)
{
	if (s.empty())
		return (false);
	std::string	str = s;
	if (s[0] == '-')
		str = s.substr(1);
	if (str.find_last_not_of("0123456789.") != std::string::npos || std::count(str.begin(), str.end(), '.') > 1
			|| str.find_first_of("0123456789") == std::string::npos)
		return (false);
	return (true);
}

const char	*BitcoinExchange::InvFile::what() const throw()
{
	return ("Error: could not open file.");
}

const char	*BitcoinExchange::InvDB::what() const throw()
{
	return ("Error: could not open database.");
}

const char	*BitcoinExchange::EmptyDB::what() const throw()
{
	return ("Error: empty database.");
}

BitcoinExchange::InvDBLine::InvDBLine(std::string const &line)
{
	_msg = "Error: bad database line => " + line;
}

BitcoinExchange::InvDBLine::~InvDBLine() throw()
{
}

const char	*BitcoinExchange::InvDBLine::what() const throw()
{
	return (_msg.c_str());
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
}

const char	*BitcoinExchange::Date404::what() const throw()
{
	return ("Error: couldn't find an appropriate date.");
}

const char	*BitcoinExchange::InvValueNeg::what() const throw()
{
	return ("Error: not a positive number.");
}

const char	*BitcoinExchange::InvValueBig::what() const throw()
{
	return ("Error: too large a number.");
}

void	BitcoinExchange::_loadDb(std::string const &path)
{
	std::ifstream	file(path.c_str());
	if (!file.is_open())
		throw BitcoinExchange::InvDB();

	std::string	line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw BitcoinExchange::InvDBLine(line);

	while (std::getline(file, line))
	{
		size_t		pos = line.find(",");
		if (pos == std::string::npos)
			throw BitcoinExchange::InvDBLine(line);

		std::string	date = line.substr(0, pos);
		std::string	val = line.substr(pos + 1);
		if (!isValidDate(date) || !isValidValue(val))
			throw BitcoinExchange::InvDBLine(line);

		double		value = std::atof(val.c_str());
		if (value < 0)
			throw BitcoinExchange::InvDBLine(line);
		_rates[date] = value;
	}
	if (_rates.empty())
		throw (BitcoinExchange::EmptyDB());
	
	file.close();
}
