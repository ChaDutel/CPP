/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:26:19 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/16 11:14:07 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weaponType) : weapon(weaponType)
{
	this->setName(name);
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << this->getName() << " attacks with their " << this->weapon.getType() << std::endl;
}

std::string	HumanA::getName()
{
	return (this->_name);
}

void	HumanA::setName(std::string name)
{
	this->_name = name;
}
