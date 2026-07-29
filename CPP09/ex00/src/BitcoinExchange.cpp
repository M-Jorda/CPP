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

}

float	BitcoinExchange::checkValue(std::string const &value)
{

}

bool		BitcoinExchange::isValidDate(std::string const &date)
{

}

const char	*BitcoinExchange::InvFile::what() const throw()
{
	return ("Error: could not open file.");
}

const char	*BitcoinExchange::InvDate::what() const throw()
{
	return ("Error: bad input => ");
};

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
	std::ifstream File(path);
	if (!File.is_open())
		throw InvFile();

	
}
