#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <fstream>
# include <map>
// # include <iomanip>
// # include <string>
// # include <limits>
// # include  <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::ifstream &file);
		~BitcoinExchange();

        std::map<std::string, double> const&	getBitcoinExchange() const;
		int		parse(std::string str);
		int		findYear(std::string str, int i, std::string line);
		int		findMonth(std::string str, int i, std::string line);
		int		findDay(std::string str, int i, std::string line, int month);
		double	findValue(std::string str, int i, std::string line);

		// utils //
		int	isDigit(char c);
		int	validDate(int nb, int min, int max);

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

        std::map<std::string, double>	data;
};

// class	GenericException 				: public std::exception {public: virtual char const*	what() const throw();};
class	LineTooShortException 				: public std::exception {public: virtual char const*	what() const throw();};
class	WrongSyntaxException 				: public std::exception {public: virtual char const*	what() const throw();};
class	NotANumberException 				: public std::exception {public: virtual char const*	what() const throw();};
class	MissArgumentException 				: public std::exception {public: virtual char const*	what() const throw();};
class	WrongDateException 				    : public std::exception {public: virtual char const*	what() const throw();};
class	TooLargeNumberException 			: public std::exception {public: virtual char const*	what() const throw();};

# endif