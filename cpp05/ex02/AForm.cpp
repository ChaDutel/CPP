/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:27:00 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/14 16:20:46 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

/// BUILDERS ///

AForm::AForm() : _name(""), _gradeSigned(50), _gradeExecute(80), _signed(false)
{
}

AForm::AForm(std::string name, int gradeSigned, int gradeExecute) : _name(name), _gradeSigned(gradeSigned), _gradeExecute(gradeExecute), _signed(false)
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

AForm::AForm(const AForm& other) : _name(other._name), _gradeSigned(other._gradeSigned), _gradeExecute(other._gradeExecute), _signed(false)
{
}

AForm& AForm::operator=(const AForm& other)
{
	(void)other;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const AForm& other)
{
	out << other.getName() << " " << other.getGradeSigned() << " " << other.getGradeExecute() << " " << other.getIsSigned();
	return (out);
}

AForm::~AForm()
{
}

/// FUNCTIONS ///

void		AForm::beSigned(const Bureaucrat	&bur)
{
	if (bur.getGrade() <= _gradeSigned)
		_signed = true;
	else
		throw GradeTooHighException();
}

// GETTERS //

std::string	AForm::getName() const
{
	return (_name);
}
int			AForm::getGradeSigned() const
{
	return (_gradeSigned);
}

int			AForm::getGradeExecute() const
{
	return (_gradeExecute);
}

bool		AForm::getIsSigned() const
{
	return (_signed);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("form Grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("form Grade is too low");
}
