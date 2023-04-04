/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:06:37 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/03 15:32:45 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/// Builders ///

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal construction done\n";
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor done\n";
}

/// Functions ///


std::string Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << getType() << " makes a weird sound!" << std::endl;
}
