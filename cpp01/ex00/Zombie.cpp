/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:22:14 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/14 15:41:19 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// BUILDERS ///

Zombie::Zombie(std::string name)
{
	Zombie::setName(name);
	Zombie::announce();
}

Zombie::~Zombie()
{
	std::cout << this->_name << " died" << std::endl;
}

std::string Zombie::getName(void)
{
	return (this->_name);
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
