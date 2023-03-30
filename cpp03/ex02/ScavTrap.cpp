/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:50:19 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/30 14:57:23 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/// Builder ///

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other._name)
{
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = other._name;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	
}

/// Functions ///

void	ScavTrap::guardGate()
{
	std::cout << _name << " enters guard gate mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints < 1)
	{
		std::cout << _name << " ScavTrap is already dead! Can't do any any action!" << std::endl;
		return ;
	}
	else if (_energyPoints > 0)
	{
		std::cout << _name << " ScavTrap attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "No more energy points for" << _name << " ScavTrap! Can't do any action!" << std::endl;
	}
}
