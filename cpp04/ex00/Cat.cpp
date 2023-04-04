/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:32:23 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/04 14:21:37 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/// Builders ///

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat construction done\n";
}

Cat::Cat(const Cat& other) : Animal()
{
	_type = other._type;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor done\n";
}

/// Functions ///

void	Cat::makeSound() const
{
	std::cout << getType() << " is mewing !" << std::endl;
}
