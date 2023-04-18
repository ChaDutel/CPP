/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:09:35 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/18 12:09:05 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(Bureaucrat bur) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = bur.getName();
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
	out << other.getName() << " " << other.getGradeSigned() << " " << other.getGradeExecute() << " " << other.getIsSigned();
	return (out);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
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
		std::cout << "Sucess! " << executor.getName() << " has been robotized." << std::endl;
	else
		std::cout << "Fail to execute the operation!" << std::endl;
}
