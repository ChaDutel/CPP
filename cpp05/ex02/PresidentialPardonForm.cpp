/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:09:35 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/18 12:05:09 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), 25, 5)
{
	this->_target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const PresidentialPardonForm& other)
{
	out << other.getName() << " sign grade is " << other.getGradeSigned() << ", execute grade is " << other.getGradeExecute() << " and signed status is " << other.getIsSigned();
	return (out);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/// FUNCTIONS ///

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned() == false || executor.getGrade() > getGradeExecute())
	{
		std::cout << "The form isn't signed or PresidentialPardonForm ";	
		throw GradeTooHighException();
	}



	std::cout << executor.getName() << " was forgiven by Zaphod Beeblebrox" << std::endl;
}
