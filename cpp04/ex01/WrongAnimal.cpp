/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:06:37 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/03 15:32:45 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/// Builders ///

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal construction called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

/// Functions ///


std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << getType() << " makes a weird \"wrong\" sound!" << std::endl;
}
