/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:45:45 by charline          #+#    #+#             */
/*   Updated: 2023/07/18 18:00:02 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "./BitcoinExchange.hpp"

//----------------------------------------------------------------- EXCEPTIONS -----------------------------------------------------------------//

char const*	LineTooShortException::what()	  		const throw() {return ("ERROR: Wrong syntax, line is too short");}
char const*	WrongSyntaxException::what()	  		const throw() {return ("ERROR: Wrong syntax");}
char const*	NotANumberException::what()				const throw() {return ("ERROR: Not a valid number");}
char const*	MissArgumentException::what()			const throw() {return ("ERROR: Miss an argument");}
char const*	WrongDateException::what()				const throw() {return ("ERROR: Wrong date");}
char const*	TooLargeNumberException::what()			const throw() {return ("ERROR: Number is too large");}
char const*	UpperThousandNumberException::what()	const throw() {return ("ERROR: Number is larger than 1000");}


//----------------------------------------------------------------- BUILDERS  -----------------------------------------------------------------//

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
	std::string	line;
	while (std::getline(file, line, '\n'))
	{
		if (line == "date,exchange_rate")
			continue;
		this->data[line.substr(0, 10)] = std::atof(line.substr(11).c_str());
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

//----------------------------------------------------------------- FUNCTIONS -----------------------------------------------------------------//

/////////////////////////////  GETTERS  /////////////////////////////

std::map<std::string, double> const&	BitcoinExchange::getDataMap() const
{
	return (this->data);
}


///////////////////////////// EXECUTION /////////////////////////////

void	BitcoinExchange::printResult(std::string date, double valueExec, double resValue)
{
	std::cout << date << " => " << valueExec << " = " << resValue << std::endl;
}

void	BitcoinExchange::exec(std::string date, double value)
{
	std::map<std::string, double> dataExec = this->getDataMap();
	

	std::map<std::string, double>::iterator it = dataExec.upper_bound(date);
	if (it == dataExec.begin())
	{
		std::cout << "ERROR: doesn't contain such an old date" << std::endl;
		return ;
	}
	else
	{
		it--;
		double	resValue = it->second * value;
		printResult(date, value, resValue);
	}
}


/////////////////////////////  PARSING  /////////////////////////////

int	BitcoinExchange::validDate(int nb, int min, int max)
{
	if (min != -1)
	{
		if (nb < min)
			return (-1);
	}
	if (max != -1)
	{
		if (nb > max)
			return (-1);
	}
	return (0);
}

int	BitcoinExchange::isDigit(char c)
{
	if (c > '9' || c < '0')
		return (-1);
	return (0);
}

void	BitcoinExchange::findValue(std::string str, int pos, std::string line)
{
	bool    point = false;
	int j = 0;
	while (str[pos])
	{
		if (isDigit(str[pos]) == -1)
		{
			if (str[pos] == '.' && point == false)
				point = true;
			else
				throw NotANumberException();
		}
		if (j > 10)
			throw TooLargeNumberException();
		line += str[pos];
		pos++;
		j++;
	}
	double res = std::atof(line.c_str());
	if (res > 1000)
		throw UpperThousandNumberException();
	return ;
}

void	BitcoinExchange::findDay(std::string str, int pos, std::string line, int month)
{
	while (str[pos] && pos< 10)
	{
		if (isDigit(str[pos]) == -1)
			throw NotANumberException();
		line += str[pos];
		pos++;
	}
	if (pos!= 10)
		throw MissArgumentException();
	int res = std::atoi(line.c_str());
	if (validDate(pos, 1, 31) == -1)
		throw WrongDateException();
	if ((month == 4 || month == 6 || month == 9 || month == 11) && res == 31)
		throw WrongDateException();
	else if (month == 02)
	{
		if (res > 28)
			throw WrongDateException();
	}
	return ;
}

int	BitcoinExchange::findMonth(std::string str, int pos, std::string line)
{
	while (str[pos] && pos< 7)
	{
		if (isDigit(str[pos]) == -1)
			throw NotANumberException();
		line += str[pos];
		pos++;
	}
	if (pos!= 7)
		throw MissArgumentException();
	int res = std::atoi(line.c_str());
	if (validDate(res, 1, 12) == -1)
		throw WrongDateException();
	return (res);
}

void	BitcoinExchange::findYear(std::string str, int pos, std::string line)
{
	while (str[pos] && pos< 4)
	{
		if (isDigit(str[pos]) == -1)
			throw NotANumberException();
		line += str[pos];
		pos++;
	}
	if (pos!= 4)
		throw MissArgumentException();
	int res = std::atoi(line.c_str());
	if (validDate(res, 2000, -1) == -1)
		throw WrongDateException();
	return ;
}

int    BitcoinExchange::parse(std::string str)
{
	std::string line;
	try
	{
		if (str.size() < 14)
			throw LineTooShortException();
		findYear(str, 0, line);
		if (str[4] != '-')
			throw WrongSyntaxException();
		int month = findMonth(str, 5, line);
		if (str[7] != '-')
			throw WrongSyntaxException();
		findDay(str, 8, line, month);
		if (str[10] != ' ')
			throw WrongSyntaxException();
		if (str[11] != '|')
			throw WrongSyntaxException();
		if (str[12] != ' ')
			throw WrongSyntaxException();
		findValue(str, 13, line);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (-1);
	}
	return (0);
}
