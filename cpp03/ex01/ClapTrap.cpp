/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:58:33 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/30 12:14:46 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/// Builder ///

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = other._name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;	
}


/// Functions ///

void			ClapTrap::printState()
{
	std::cout << _name << " has " << _hitPoints << " hit points and " << _energyPoints << " energy points" << std::endl;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	if (this->_hitPoints == 0)
		return (0);
	return (this->_attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints < 1)
	{
		std::cout << _name << " is already dead! Can't do any any action!" << std::endl;
		return ;
	}
	else if (_energyPoints > 0)
	{
		std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "No more energy points! Can't do any action!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int	i;

	if (_hitPoints < 1)
	{
		std::cout << _name << " is already dead!" << std::endl;
		return ;
	}
	else
	{
		std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
		i = _hitPoints - amount;
		if (i < 1)
		{
			std::cout << _name << " dies!" << std::endl;
			_hitPoints = 0;
		}
		else
			_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints < 1)
	{
		std::cout << _name << " is already dead! Can't do any any action!" << std::endl;
		return ;
	}
	if (_energyPoints > 0)
	{
		std::cout << _name << " recovered " << amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "No more energy points! Can't do any action!" << std::endl;
	}
}
