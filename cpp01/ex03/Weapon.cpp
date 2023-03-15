/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:24:44 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/15 17:45:48 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string nameType)
{
    this->setType(nameType);
}

Weapon::~Weapon()
{
}

const std::string&    Weapon::getType() const
{
    return (this->type);
}

void    Weapon::setType(std::string weaponType)
{
    this->type = weaponType;
}
