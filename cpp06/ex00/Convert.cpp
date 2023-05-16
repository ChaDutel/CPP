/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:47:57 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/15 15:49:52 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Convert.hpp"

//----------------------------------------------------------------- BUILDERS -----------------------------------------------------------------//

Convert::Convert()
{
}

Convert::Convert(const Convert& other)
{
	(void)other;
}

Convert& Convert::operator=(const Convert& other)
{
	(void)other;
	return (*this);
}

Convert::~Convert()
{
}



//----------------------------------------------------------------- FUNCTIONS -----------------------------------------------------------------//

/// PRINT AND CAST ///

void	Convert::printExc(const char *c, const char *i, const char *f, const char *d)
{
	std::cout << "char: " << c << "\nint: " << i << "\nfloat: " << f << "\ndouble: " << d << std::endl;
}

void	Convert::printResult(char c, int i, float f, double d)
{
	double	diff = d - i;
	
	if (d > 2147483647 || d < -2147483648)
		std::cout << std::fixed << std::setprecision(1) << "char: impossible" << "\nint: impossible" << "\nfloat: " << f << "f\ndouble: " << d << std::endl;
	else if (d > 127 || d < 0 || diff != 0)
		std::cout << std::fixed << std::setprecision(1) << "char: impossible" << "\nint: " << i << "\nfloat: " << f << "f\ndouble: " << d << std::endl;
	else if (((c >= 0 && c <= 31) || c == 127) && (d == 127 || (d >= 0 && d <= 31)))
		std::cout << std::fixed << std::setprecision(1) << "char: Non displayable" << "\nint: " << i << "\nfloat: " << f << "f\ndouble: " << d << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1) << "char: '" << c << "'\nint: " << i << "\nfloat: " << f << "f\ndouble: " << d << std::endl;
	}
}

void	Convert::castChar(char *str)
{
	char c = str[0];

	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	printResult(c, i, f, d);
}

void	Convert::castDouble(char *str)
{
	double d = std::atof(str);

	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);

	printResult(c, i, f, d);
}

void	Convert::castFloat(char *str)
{
	float f = static_cast<float>(std::atof(str));

	char	c = static_cast<char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);

	printResult(c, i, f, d);
}

void	Convert::castInt(char * str)
{
	int		i = std::atoi(str);

	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	printResult(c, i, f, d);
}


void	Convert::printGoodType(int identifiedType, char *str)
{
	switch (identifiedType)
	{
		case 0 :
			printExc("impossible", "impossible", "inff", "inf");
			break;
		case 1 :
			printExc("impossible", "impossible", "-inff", "-inf");
			break;
		case 2 :
			castInt(str);
			break;
		case 3 :
			castFloat(str);
			break;
		case 4 :
			castDouble(str);
			break;
		case 5 :
			castChar(str);
			break;
		default :
			printExc("impossible", "impossible", "nanf", "nan");
			break;
	}
}



/// FIND TYPE ///

int    Convert::isChar(char *str)    
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] < 32 || str[i] > 126))
			return (-1);
		else if (i > 0)
			return (-1);
	}
	return (0);
}

int	Convert::isDouble(char *str)
{
	int i = 0;
	int	j = 0;
	int	k = 0;

	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-' && str[i] != '.'))
			return (-1);
		else if (i != 0 && (str[i] == '+' || str[i] == '-'))
			return (-1);
		else if (str[i] == '.')
			j++;
		else if (str[i] >= '0' && str[i] <= '9')
			k++;
		i++;
	}
	if (j > 1 || k < 1)
		return (-1);
	return (0);
}

int	Convert::isFloat(char *str)
{
	int i = 0;
	int	j = 0;
	int	k = 0;
	int	l = 0;

	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-' && str[i] != '.' && str[i] != 'f'))
			return (-1);
		else if (i != 0 && (str[i] == '+' || str[i] == '-'))
			return (-1);
		else if (str[i] == '.')
			j++;
		else if (str[i] >= '0' && str[i] <= '9')
			k++;
		else if (str[i] == 'f')
			l++;
		i++;
	}
	i--;
	if (str[i] != 'f' || j > 1 || k < 1 || l != 1)
		return (-1);
	return (0);
}

int    Convert::isInt(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != '+' && str[i] != '-'))
			return (-1);
		else if (i != 0 && (str[i] == '+' || str[i] == '-'))
			return (-1);
	}
	double tmp = std::strtod(str, NULL);
	if (tmp > 2147483647 || tmp < -2147483648)
		return (-1);
	return (0);
}

int	Convert::isInfNeg(std::string str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::tolower(str[i]);
	if (str == "-inf" || str == "-inff")
		return (0);
	return (-1);
}

int	Convert::isInfPos(std::string str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::tolower(str[i]);
	if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
		return (0);
	return (-1);
}

int	Convert::findType(char *str)
{
	std::string	sstr = str;
	if (isInfPos(sstr) == 0)
		return (0);
	else if (isInfNeg(sstr) == 0)
		return (1);

	else if (isInt(str) == 0)
		return (2);
	else if (isFloat(str) == 0)
		return (3);
	else if (isDouble(str) == 0)
		return (4);
	else if (isChar(str) == 0)
		return (5);
	else
		return (6);
}
