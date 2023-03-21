/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:49:37 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/21 14:24:49 by cdutel-l         ###   ########lyon.fr   */
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
	std::cout << "DEBUG complain: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}

void	Harl::_info(void)
{
	std::cout << "INFO complain: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !\n";
}

void	Harl::_warning(void)
{
	std::cout << "WARNING complain: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::_error(void)
{
	std::cout << "ERROR complain: This is unacceptable ! I want to speak to the manager now.\n";
}

void    Harl::complain(std::string level)
{
	PointerArray   array[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string    levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (levelArray[i] == level)
			(this->*array[i])();
	}
}
