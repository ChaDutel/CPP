#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <cstdlib>
# include <fstream>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::ifstream &file);
		~BitcoinExchange();

        std::map<std::string, double> const&	getDataMap() const;
		int		parse(std::string str);
		void	findYear(std::string str, int i, std::string line);
		int		findMonth(std::string str, int i, std::string line);
		void	findDay(std::string str, int i, std::string line, int month);
		void	findValue(std::string str, int i, std::string line);

		void	exec(std::string date, double value);
		void	printResult(std::string date, double valueExec, double resValue);

		// utils //
		int		isDigit(char c);
		int		validDate(int nb, int min, int max);

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

        std::map<std::string, double>	data;
};

class	LineTooShortException 				: public std::exception {public: virtual char const*	what() const throw();};
class	WrongSyntaxException 				: public std::exception {public: virtual char const*	what() const throw();};
class	NotANumberException 				: public std::exception {public: virtual char const*	what() const throw();};
class	MissArgumentException 				: public std::exception {public: virtual char const*	what() const throw();};
class	WrongDateException 				    : public std::exception {public: virtual char const*	what() const throw();};
class	TooLargeNumberException 			: public std::exception {public: virtual char const*	what() const throw();};
class	UpperThousandNumberException 		: public std::exception {public: virtual char const*	what() const throw();};

# endif
