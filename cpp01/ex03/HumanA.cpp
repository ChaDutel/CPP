/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charline <charline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:26:19 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/20 11:58:59 by charline         ###   ########.fr       */
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

std::string	HumanA::getName() const
{
	return (this->_name);
}

void	HumanA::setName(std::string name)
{
	this->_name = name;
}
