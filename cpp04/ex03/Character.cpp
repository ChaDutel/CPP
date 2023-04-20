/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:07:16 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/20 17:23:01 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

/// Builders ///

Character::Character() : _name("")
{
}

Character::Character(std::string name) : _name(name)
{
}

Character::Character(const Character& other)
{
	this->_name = other._name;
}

Character& Character::operator=(const Character& other)
{
	// for (int i = 0; i < 4; i++)
	// 	_items[i] = "";

	
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
	
}

void 				Character::unequip(int idx)
{
	
}

void 				Character::use(int idx, ICharacter& target)
{
	_items[idx].use(target);
}
