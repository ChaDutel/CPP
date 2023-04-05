/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:06:37 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/05 11:11:06 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/// Builders ///

AAnimal::AAnimal() : _type("Animal")
{
	std::cout << "Animal construction done\n";
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor done\n";
}

/// Functions ///


std::string AAnimal::getType() const
{
	return (this->_type);
}

