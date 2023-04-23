/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:07:16 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/23 13:25:48 by cdutel-l         ###   ########lyon.fr   */
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
	for (int i = 0; i < 4; i++)
	{
		if (other._items[i])
			this->_items[i] = other._items[i]->clone();
		else
			this->_items[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_items[i])
			delete this->_items[i];
		else if (other._items[i])
			this->_items[i] = other._items[i]->clone();
		else
			this->_items[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_items[i])
			delete _items[i];
	}
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
	if (idx < 4 && idx >= 0)
		_items[idx] = NULL;
}

void 				Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && this->_items[idx])
	{
		this->_items[idx]->use(target);
		delete this->_items[idx];
		this->_items[idx] = NULL;
	}
}
