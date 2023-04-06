/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:26:58 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/06 15:36:48 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/// BUILDERS ///

Bureaucrat::Bureaucrat() : _name("")
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
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

void	Bureaucrat::incrementation(int i)
{
	int	tmpGrade;
	
	tmpGrade = getGrade() - i;
	if (tmpGrade < 1)
		throw std::exception();
	else
		setGrade(tmpGrade);
}

void	Bureaucrat::decrementation(int i)
{
	int	tmpGrade;
	
	tmpGrade = getGrade() + i;
	if (tmpGrade > 150)
		throw std::exception();
	else
		setGrade(tmpGrade);
}
