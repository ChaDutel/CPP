/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:56:12 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/06 15:42:14 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	 worker("John", 5);
	Bureaucrat	 highWorker("Will", 5);

	try
	{
		worker.incrementation(2);
		std::cout << worker.getName() << " grade is " << worker << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Grade too high or low!" << std::endl;
	}
	try
	{
		for (int i = 0; i < 15; i++)
		{
			highWorker.incrementation(i);
			std::cout << highWorker.getName() << " grade is " << highWorker << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Grade too high or low!" << std::endl;
	}
	return (0);
}
