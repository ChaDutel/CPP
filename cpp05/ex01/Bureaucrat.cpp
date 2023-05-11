/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:26:58 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/11 16:05:32 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/// BUILDERS ///

Bureaucrat::Bureaucrat() : _name("")
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 150)
        throw(GradeTooLowException());
    else if (grade < 1)
        throw(GradeTooHighException());
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_grade = other._grade;
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

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void		Bureaucrat::setGrade(int i)
{
	this->_grade = i;
}

void	Bureaucrat::incrementation()
{
	int	tmpGrade;
	
	tmpGrade = getGrade() - 1;
	if (tmpGrade < 1)
		throw (GradeTooHighException());
	else
		setGrade(tmpGrade);
}

void	Bureaucrat::decrementation()
{
	int	tmpGrade;
	
	tmpGrade = getGrade() + 1;
	if (tmpGrade > 150)
		throw (GradeTooLowException());
	else
		setGrade(tmpGrade);
}

void	Bureaucrat::signForm(Form forms)
{
	try
	{
		forms.beSigned(*this);
		std::cout << _name << " signed " << forms.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << forms.getName() << " because " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high, it's less than 1");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, it's more than 150");
}
