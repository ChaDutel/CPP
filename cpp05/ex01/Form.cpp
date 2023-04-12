/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:27:00 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/12 16:12:30 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

/// BUILDERS ///

Form::Form() : _name(""), _gradeSigned(50), _gradeExecute(80), _signed(false)
{
}

Form::Form(std::string name, int gradeSigned, int gradeExecute) : _name(name), _gradeSigned(gradeSigned), _gradeExecute(gradeExecute), _signed(false)
{
	if (gradeSigned < 1)
		throw GradeTooHighException();
	if (gradeSigned > 150)
		throw GradeTooLowException();

	if (gradeExecute < 1)
		throw GradeTooHighException();
	if (gradeExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _gradeSigned(other._gradeSigned), _gradeExecute(other._gradeExecute), _signed(false)
{
}

Form& Form::operator=(const Form& other)
{	
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Form& other)
{
	out << other.getName() << " " << other.getGradeSigned() << " " << other.getGradeExecute() << " " << other.getIsSigned();
	return (out);
}

Form::~Form()
{
}

/// FUNCTIONS ///

void		Form::beSigned(Bureaucrat	bur)
{
	if (bur.getGrade() <= _gradeSigned)
		_signed = true;
	else
		throw GradeTooLowException();
}

// GETTERS //
std::string	Form::getName() const
{
	return (_name);
}
int			Form::getGradeSigned() const
{
	return (_gradeSigned);
}

int			Form::getGradeExecute() const
{
	return (_gradeExecute);
}

bool		Form::getIsSigned() const
{
	return (_signed);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high, it's less than 1");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, it's more than 150");
}
