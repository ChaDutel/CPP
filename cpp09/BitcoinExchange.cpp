/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:45:45 by charline          #+#    #+#             */
/*   Updated: 2023/07/04 15:06:47 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./BitcoinExchange.hpp"

//----------------------------------------------------------------- EXCEPTIONS -----------------------------------------------------------------//

// char const*	GenericException::what()				const throw() {return ("ERROR: GenericException placeholder");}
char const*	LineTooShortException::what()	  		const throw() {return ("ERROR: Wrong syntax, line is too short");}
char const*	WrongSyntaxException::what()	  		const throw() {return ("ERROR: Wrong syntax");}
char const*	NotANumberException::what()				const throw() {return ("ERROR: Not a number");}
char const*	MissArgumentException::what()			const throw() {return ("ERROR: Miss an argument");}
char const*	WrongDateException::what()				const throw() {return ("ERROR: Wrong date");}
char const*	TooLargeNumberException::what()			const throw() {return ("ERROR: Number is too large");}


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
		if (line == "2009-01-02,0")
			std::cout << line.substr(0, 10) << " " << std::atof(line.substr(11).c_str()) << std::endl;
	}
	// for (std::map<std::string, float>::iterator it = this->clients.begin(); it != this->clients.end(); it++)
	// {
	// 	this->data[it->first]
		
	// }
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

///////////////////////////// PARSING /////////////////////////////

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

double	BitcoinExchange::findValue(std::string str, int i, std::string line)
{
	bool    point = false;
	int j = 0;
	while (str[i])
	{
		if (isDigit(str[i]) == -1)
		{
			if (str[i] == '.' && point == false)
				point = true;
			else
				throw NotANumberException();
		}
		if (j > 10)
			throw TooLargeNumberException();
		line += str[i];
		i++;
		j++;
	}
	double res = std::atof(line.c_str());
	return (res);
}

int	BitcoinExchange::findDay(std::string str, int i, std::string line, int month)
{
	// std::string month = str[i - 3] = str[i - 2];
	while (str[i] && i < 10)
	{
		if (isDigit(str[i]) == -1)
			throw NotANumberException();
		line += str[i];
		i++;
	}
	std::cout << i << std::endl;
	if (i != 10)
		throw MissArgumentException();
	int res = std::atoi(line.c_str());
	if (validDate(i, 1, 31) == -1)
		throw WrongDateException();
	if ((month == 4 || month == 6 || month == 9 || month == 11) && res == 31)
	// if (month == 04 || month == 06 || month == 09 || month == 11 && res == 31)
		throw WrongDateException();
	else if (month == 02) // bisex
	{
		if (res > 28)
			throw WrongDateException();
		// if (i == 29 && year/4) // bisex to do
		// else
		//     return (-1);
	}
	return (res);
}

int	BitcoinExchange::findMonth(std::string str, int i, std::string line)
{
	while (str[i] && i < 7)
	{
		if (isDigit(str[i]) == -1)
			throw NotANumberException();
		line += str[i];
		i++;
	}
	if (i != 7)
		throw MissArgumentException();
	int res = std::atoi(line.c_str());
	std::cout << res << std::endl;
	if (validDate(res, 1, 12) == -1)
		throw WrongDateException();
	return (res);
}

int	BitcoinExchange::findYear(std::string str, int i, std::string line)
{
	while (str[i] && i < 4)
	{
		std::cout << str[i] << std::endl;
		if (isDigit(str[i]) == -1)
			throw NotANumberException();
		line += str[i];
		i++;
	}
	if (i != 4)
		throw MissArgumentException();
	int res = std::atoi(line.c_str());
	if (validDate(res, 2000, -1) == -1) //  2009
		throw WrongDateException();
	return (res);
}

int    BitcoinExchange::parse(std::string str)
{
	std::string line;
	try
	{
		if (str.size() < 14)
			throw LineTooShortException();
		int year = findYear(str, 0, line);
		if (str[4] != '-')
			throw WrongSyntaxException();
		int month = findMonth(str, 5, line);
		if (str[7] != '-')
			throw WrongSyntaxException();
		int day = findDay(str, 8, line, month);
		if (str[10] != ' ')
			throw WrongSyntaxException();
		if (str[11] != '|')
			throw WrongSyntaxException();
		if (str[12] != ' ')
			throw WrongSyntaxException();
		double value = findValue(str, 13, line);
		std::cout << "My Parse : " << year << " " << month << " "  << day << " " << value << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (-1);
	}
	std::cout << "GOOD :     ";
	for (int i = 0; str[i]; i++)
		std::cout << str[i];
	std::cout << std::endl;
	return (0);
}

// int    BitcoinExchange::parse(std::string str)
// {
// 	int i = 0;
// 	std::string line;
// 	try
// 	{
// 		if (str.size() < 14)
// 			throw LineTooShortException();
// 		int year = findYear(str, &i, line);
// 		if (str[i++] != '-')
// 			throw WrongSyntaxException();
// 		int month = findMonth(str, &i, line);
// 		if (str[i++] != '-')
// 			throw WrongSyntaxException();
// 		int day = findDay(str, &i, line, month);
// 		if (str[i++] != ' ')
// 			throw WrongSyntaxException();
// 		if (str[i++] != '|')
// 			throw WrongSyntaxException();
// 		if (str[i++] != ' ')
// 			throw WrongSyntaxException();
// 		int value = findValue(str, &i, line);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 		return (-1);
// 	}
// 	return (0);
// }