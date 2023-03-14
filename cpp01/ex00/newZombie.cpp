/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:22:11 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/14 15:19:02 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::_newZombie(std::string name)
{
	Zombie*	newZombie = new Zombie(name);
	
	return (newZombie);
}

Zombie* Zombie::getNewZombie(std::string name)
{
	return (this->_newZombie(name));
}
