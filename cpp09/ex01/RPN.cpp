/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:18:48 by charline          #+#    #+#             */
/*   Updated: 2023/07/05 18:28:58 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./RPN.hpp"

//----------------------------------------------------------------- EXCEPTIONS -----------------------------------------------------------------//

char const*	WrongSyntaxException::what()	  		const throw() {return ("ERROR: Wrong syntax");}
char const*	TooFewNumberException::what()			const throw() {return ("ERROR: Miss a number to execute the operation");}
char const*	TooFewNumbersException::what()			const throw() {return ("ERROR: Miss a number or more to execute the operation");}
char const*	TooMuchNumbersException::what()			const throw() {return ("ERROR: Too much numbers");}
char const*	TooMuchNbOrOpException::what()			const throw() {return ("ERROR: Too much numbers or operators to handle");}
char const*	ZeroDivException::what()				const throw() {return ("ERROR: Cannot divided a number with 0");}


//----------------------------------------------------------------- BUILDERS  -----------------------------------------------------------------//

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return (*this);
}

RPN::~RPN()
{
}

//----------------------------------------------------------------- FUNCTIONS -----------------------------------------------------------------//

/////////////////////////// GETTERS/SETTERS ///////////////////////////

std::stack<double> RPN::getNbStack() {return (this->nbStack);}

void			RPN::addNb(double nb) {this->nbStack.push(nb);}

double				RPN::removeNb()
{
	double topValue = this->nbStack.top();
	this->nbStack.pop();
	return (topValue);
}


/////////////////////////////   UTILS   /////////////////////////////

bool	RPN::isOperator(char c)
{
	if (c != '+' && c != '-' && c != '*' && c != '/')
		return (false);
	return (true);
}

bool	RPN::isDigit(char c)
{
	if (c > '9' || c < '0')
		return (false);
	return (true);
}


///////////////////////////// EXECUTION /////////////////////////////

void	RPN::exec(const char c)
{
	if (isDigit(c))
	{
		addNb(std::atoi(&c));
		return ;
	}
	else
	{
		if (getNbStack().size() < 2)
			throw TooFewNumberException();
		double	rightNB = removeNb();
		double	leftNB = removeNb();
		double res = 0;
		if (c == '+')
			res = leftNB + rightNB;
		else if (c == '-')
			res = leftNB - rightNB;
		else if (c == '*')
			res = leftNB * rightNB;
		else if (c == '/')
		{
			if (rightNB == 0)
				throw ZeroDivException();
			else
				res = leftNB / rightNB;
		}
		addNb(res);
	}
	return ;
}


/////////////////////////////  PARSING  /////////////////////////////

void	RPN::parse(std::string str)
{
	if (str.size() > 100)
		throw TooMuchNbOrOpException();
	int		countOp = 0;
	int		countNb = 0;
	for (int i = 0; str[i]; i++)
	{
		if (isDigit(str[i]) == false)
		{
			if (isOperator(str[i]) == false && str[i] != ' ')
				throw WrongSyntaxException();
			if (str[i] != ' ')
				countOp++;
		}
		else
			countNb++;
	}
	if (countNb != (countOp + 1))
	{
		if (countNb > (countOp + 1))
			throw TooMuchNumbersException();
		else
			throw TooFewNumbersException();
	}
}