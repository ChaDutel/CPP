/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:56:12 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/14 14:08:48 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	worker("John", 5);
	Bureaucrat	highWorker("Will", 5);
	Form		form("forms", 60, 160);
	
	try
	{
		Bureaucrat Louis("Louis", 141);
		
		Louis.decrementation();
	}
	catch (std::exception &e)
	{
		std::cout <<e.what() << std::endl;
	}
	try
	{
		worker.incrementation();
		std::cout << worker.getName() << " grade is " << worker << std::endl;

		worker.signForm(form);
		// Louis.decrementation();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		for (int i = 0; i < 4; i++)
		{
			highWorker.incrementation();
			std::cout << highWorker.getName() << " grade is " << highWorker << std::endl;
		}
		// highWorker.incrementation();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
