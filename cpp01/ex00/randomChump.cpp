/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:23:07 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/14 15:37:11 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::randomChump(std::string name)
{
	std::string	tmpName;

	tmpName = this->getName();
	this->setName(name);
	this->announce();
	std::cout << this->_name << " died" << std::endl;
	this->setName(tmpName);
}
