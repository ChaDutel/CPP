/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:26:19 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/16 11:13:15 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon("")
{
	this->setName(name);
}

HumanB::~HumanB()
{
}

void    HumanB::attack()
{
	if (this->weapon.getType() == "")
		std::cout << this->getName() << " attacks with their bare fists and feet" << std::endl;
	else
		std::cout << this->getName() << " attacks with their " << this->weapon.getType() << std::endl;
}

std::string HumanB::getName()
{
    return (this->_name);
}

void    HumanB::setName(std::string name)
{
	this->_name = name;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}
