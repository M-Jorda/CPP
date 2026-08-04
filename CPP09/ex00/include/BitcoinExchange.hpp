#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <exception>
# include <cstdlib>

# define DATE_LEN	10
# define LONG_MESS	31
# define SHORT_MESS	30

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string dbPath);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		float	getRate(std::string const &date) const;
		void	printRates();

		static void	checkValue(float const &value);
		static bool	isValidDate(std::string const &date);

		class InvFile : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class InvDate : public std::exception
		{
			public:
				InvDate(std::string const &line);
				~InvDate() throw();
				virtual const char	*what() const throw();

				private:
					std::string _msg;
		};

		class Date404 : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class InvValueNeg : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	InvValueBig : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		std::map<std::string, float> _rates;

		void	_loadDb(std::string const &path);
};

#endif
