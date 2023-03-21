/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:49:37 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/21 15:28:10 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}

void	Harl::_info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !\n";
}

void	Harl::_warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::_error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable ! I want to speak to the manager now.\n";
}

void	Harl::switchChoose(int i)
{
	while (i < 4)
	{
		switch (i)
		{
			case 0 :
				this->_debug();
				break;
			case 1 :
				this->_info();
				break;
			case 2 :
				this->_warning();
				break;
			case 3 :
				this->_error();
				break;
			default :
				break;
		}
		i++;
	}
}

void    Harl::complain(std::string level)
{
	int	count;
	std::string    levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (levelArray[i] == level)
		{
			count++;
			switchChoose(i);
		}
	}
	if (count == 0)
		std::cout << "[ Probably complaining about insignificant problems ]\n";
}
