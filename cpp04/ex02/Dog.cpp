/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:32:23 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/04 19:17:42 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/// Builders ///

Dog::Dog() : AAnimal()
{
	_type = "Dog";
	_brain = new	Brain();
	std::cout << "Dog construction done\n";
}

Dog::Dog(const Dog& other) : AAnimal()
{
	_type = other._type;
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor done\n";
}

/// Functions ///

void	Dog::makeSound() const
{
	std::cout << getType() << " is woofing!" << std::endl;
}
