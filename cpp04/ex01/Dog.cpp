/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:32:23 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/23 17:39:43 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/// Builders ///

Dog::Dog() : Animal()
{
	std::cout << "Dog construction called\n";
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal()
{
	std::cout << "Dog Copy constructor called" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	this->_type = other._type;
	for (int i = 0; i < 100; i++)
		this->_brain->setIdeas(other._brain->getIdeas(i));
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete _brain;
}

/// Functions ///

void	Dog::makeSound() const
{
	std::cout << getType() << " is woofing!" << std::endl;
}

void		Dog::learn(std::string idea)
{
	this->_brain->setIdeas(idea);
}

std::string	Dog::getLearn(int i) const
{
	return (this->_brain->getIdeas(i));
}
