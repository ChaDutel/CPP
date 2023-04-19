/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:56:12 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/19 12:08:08 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int	main()
{
	Intern	internNoob;

	internNoob.makeForm("ShrubberyCreationForm", "Jean");
	std::cout << std::endl;
	internNoob.makeForm("WrongForm", "Luka");


	try 
	{
		Bureaucrat boss("Boss", 5);
		ShrubberyCreationForm	shrub("garden");
		RobotomyRequestForm		robot("robotRequest");
		PresidentialPardonForm	president("president");

		shrub.beSigned(boss);
		shrub.execute(boss);
		std::cout << std::endl;

		boss.executeForm(robot);
		std::cout << std::endl;
		
		robot.beSigned(boss);
		robot.execute(boss);
		boss.executeForm(robot);
		std::cout << std::endl;

		president.beSigned(boss);
		president.execute(boss);
		
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;		
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat	worker("John", 5);
		Bureaucrat	highWorker("Will", 5);
		
			
			worker.incrementation();
			std::cout << worker.getName() << " grade is " << worker << std::endl;

			std::cout << std::endl;
		for (int i = 0; i < 4; i++)
		{
			highWorker.incrementation();
			std::cout << highWorker.getName() << " grade is " << highWorker << std::endl;
		}
		highWorker.incrementation();
		std::cout << highWorker.getName() << " grade is " << highWorker << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat Louis("Louis", 150);

		std::cout << std::endl << Louis.getName() << " grade is " << Louis << std::endl;
		// Louis.decrementation();
		// std::cout << Louis.getName() << " grade is " << Louis << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
	return (0);
}
