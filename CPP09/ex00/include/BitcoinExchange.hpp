#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <exception>
# include <cstdlib>
# include <algorithm>
# include <iomanip>
# include <cctype>

// Length of a YYYY-MM-DD date.
# define DATE_LEN	10
// Number of days in a long and in a short month (February is handled apart).
# define LONG_MESS	31
# define SHORT_MESS	30

class BitcoinExchange
{
	public:
		// Default constructor: empty database, every getRate call throws.
		BitcoinExchange();
		// Build the exchange from a csv database.
		// @param dbPath  path of the database, e.g. "data.csv"
		BitcoinExchange(std::string dbPath);
		// Copy constructor: copies the rates.
		// @param other  instance to copy
		BitcoinExchange(const BitcoinExchange &other);
		// Assignment operator: same copy as the copy constructor.
		// @param other  instance to copy
		// @return       *this
		BitcoinExchange &operator=(const BitcoinExchange &other);
		// Destructor: nothing to free, the map manages its own memory.
		~BitcoinExchange();

		// Rate at the given date, or at the closest lower date of the
		// database if the date is not in it. Throws Date404 if the date is
		// before the first one of the database.
		// @param date  valid YYYY-MM-DD date
		// @return      exchange rate
		double	getRate(std::string const &date) const;

		// Check the range of a value: throws InvValueNeg below 0 and
		// InvValueBig above 1000.
		// @param value  value read from the input file
		static void	checkValue(double const &value);
		// Check the YYYY-MM-DD format and that the date exists in the
		// calendar, leap years included.
		// @param date  date to check
		// @return      true if the date is valid
		static bool	isValidDate(std::string const &date);
		// Check that a string is a number: an optional '-', digits and at
		// most one '.', with at least one digit ("-3", "1.5", ".5").
		// @param s  string to check
		// @return   true if s can be converted with atof
		static bool	isValidValue(std::string const &s);

		// Thrown when the program has no argument, or when the input file
		// cannot be opened or read.
		class InvFile : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Thrown when the program has more than one argument.
		class InvUsage : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Thrown when the database cannot be opened or read.
		class InvDB : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Thrown when the database holds no rate after its header.
		class EmptyDB : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Thrown when a database line is malformed (header, date or rate).
		// @param line  the bad line, shown in the message
		class InvDBLine : public std::exception
		{
			public:
				InvDBLine(std::string const &line);
				~InvDBLine() throw();
				virtual const char	*what() const throw();

				private:
					std::string _msg;
		};

		// Thrown when an input line is malformed: no " | " separator,
		// invalid value or invalid date.
		// @param line  the bad line, shown in the message
		class InvDate : public std::exception
		{
			public:
				InvDate(std::string const &line);
				~InvDate() throw();
				virtual const char	*what() const throw();

				private:
					std::string _msg;
		};

		// Thrown when a date is before the first date of the database.
		class Date404 : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Thrown when a value is negative.
		class InvValueNeg : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		// Thrown when a value is greater than 1000.
		class	InvValueBig : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		std::map<std::string, double> _rates;

		// Read the database into _rates. The first line must be the
		// "date,exchange_rate" header; each other line a valid date and a
		// positive rate. Empty lines are skipped.
		// Throws InvDB, InvDBLine or EmptyDB.
		// @param path  path of the database
		void	_loadDb(std::string const &path);
};

#endif
