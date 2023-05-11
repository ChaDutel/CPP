/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:09:35 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/11 17:16:16 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), 72, 45)
{
	this->_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const RobotomyRequestForm& other)
{
	out << other.getName() << " sign grade is " << other.getGradeSigned() << ", execute grade is " << other.getGradeExecute() << " and signed status is " << other.getIsSigned();
	return (out);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/// FUNCTIONS ///

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned() == false || executor.getGrade() > getGradeExecute())
	{
		std::cout << "The form isn't signed or RobotomyRequestForm ";	
		throw GradeTooHighException();
	}



	int nb;

	std::cout << "Doing drill noises!" << std::endl;
	std::srand(std::time(0));
	nb = std::rand();
	if (nb % 2 == 0)
		std::cout << "Success! " << getTarget() << " has been robotized." << std::endl;
	else
		std::cout << "Fail to execute the operation!" << std::endl;
}
