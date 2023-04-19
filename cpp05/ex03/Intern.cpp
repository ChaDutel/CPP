/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:26:58 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/19 12:04:25 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/// BUILDERS ///

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	*this = other;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Intern& other)
{
	out << other;
	return (out);
}

Intern::~Intern()
{
}

/// FUNCTIONS ///

AForm	*Intern::switchChoose(int i, std::string dst)
{
	while (i < 3)
	{
		switch (i)
		{
			case 0 :
				return (new ShrubberyCreationForm(dst));
			case 1 :
				return (new RobotomyRequestForm(dst));
			case 2 :
				return (new PresidentialPardonForm(dst));
			default :
				break;
		}
		i++;
	}
	return (NULL);
}

AForm	*Intern::makeForm(std::string formName, std::string dst)
{
	int	count;
	std::string    levelArray[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (levelArray[i] == formName)
		{
			count++;
			std::cout << "Intern creates " << formName << std::endl;
			return (switchChoose(i, dst));
		}
	}
	if (count == 0)
		std::cout << "The Intern can't find the form \"" << formName << "\"" << std::endl;
	return (NULL);
}
