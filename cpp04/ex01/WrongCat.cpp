/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:32:23 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/04 14:21:37 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/// Builders ///

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat construction called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal()
{
	_type = other._type;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

/// Functions ///

void	WrongCat::makeSound() const
{
	std::cout << getType() << " is mewing !" << std::endl;
}
