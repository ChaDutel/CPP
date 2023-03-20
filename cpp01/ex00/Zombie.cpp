/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:22:14 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/20 11:40:59 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/// BUILDERS ///

Zombie::Zombie(std::string name): _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << " died" << std::endl;
}

std::string Zombie::getName(void) const
{
	return (this->_name);
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
