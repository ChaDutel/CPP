/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:56:12 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/19 12:13:41 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	worker("John", 5);
		Bureaucrat	highWorker("Will", 5);
		Form		form("forms", 3, 40);
		Form		formul("formu", 5, 40);
		
			
			worker.incrementation();
			std::cout << worker.getName() << " grade is " << worker << std::endl;

			worker.signForm(form);
			worker.signForm(formul);
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
		Form		formul("formu", 155, 40);

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat Louis("Louis", 150);

		std::cout << Louis.getName() << " grade is " << Louis << std::endl;
		Louis.decrementation();
		std::cout << Louis.getName() << " grade is " << Louis << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
