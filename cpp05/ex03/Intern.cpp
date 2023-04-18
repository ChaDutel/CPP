/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:26:58 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/18 16:19:51 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/// BUILDERS ///

Bureaucrat::Bureaucrat() : _name("")
{
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    if (grade > 150)
        throw(GradeTooLowException());
    else if (grade < 1)
        throw(GradeTooHighException());
    _name = name;
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_name = other._name;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& other)
{
	out << other.getGrade();
	return (out);
}

Bureaucrat::~Bureaucrat()
{
}

/// FUNCTIONS ///

AForm	*makeForm(std::string formName, std::string dst)
{
	std::string    levelArray[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (levelArray[i] == formName)
		{
			AForm	newForm = new AForm(formName, 1, 1);
			std::cout << "Intern creates " << formName << std::endl;
			newForm._target = dst;
			return (*newForm);
		}
	}
	std::cout << "The Intern can't find the form" << std::endl;
}

// void    Harl::complain(std::string level)
// {
// 	PointerArray   array[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
// 	std::string    levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (levelArray[i] == level)
// 			(this->*array[i])();
// 	}
// }


const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high, it's less than 1");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, it's more than 150");
}
