/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:07:16 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/21 15:45:26 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

/// Builders ///

Character::Character() : _name("")
{
	for (int i = 0; i < 4; i++)
		_items[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_items[i] = NULL;
}

Character::Character(const Character& other)
{
	this->_name = other._name;
}

Character& Character::operator=(const Character& other)
{
	
	(void)other;
	return (*this);
}

Character::~Character()
{
}

/// Functions ///

std::string const & Character::getName() const
{
	return (_name);
}

void 				Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_items[i])
		{
			_items[i] = m;
			return ;
		}
	}
}

void 				Character::unequip(int idx)
{
	_items[idx] = NULL;
}

void 				Character::use(int idx, ICharacter& target)
{
	this->_items[idx]->use(target);
}
