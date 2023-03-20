/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:26:19 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/20 12:20:33 by charline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(NULL)
{
	this->setName(name);
}

HumanB::~HumanB()
{
}

void    HumanB::attack()
{
	if (!this->weapon)
		std::cout << this->getName() << " attacks with their bare fists and feet" << std::endl;
	else
		std::cout << this->getName() << " attacks with their " << this->weapon->getType() << std::endl;
}

std::string HumanB::getName() const
{
    return (this->_name);
}

void    HumanB::setName(std::string name)
{
	this->_name = name;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
