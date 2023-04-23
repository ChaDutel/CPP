/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:32:23 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/23 17:39:55 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/// Builders ///

Cat::Cat() : Animal()
{
	std::cout << "Cat construction called\n";
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal()
{
	std::cout << "Cat Copy constructor called" << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	this->_type = other._type;
	for (int i = 0; i < 100; i++)
		this->_brain->setIdeas(other._brain->getIdeas(i));
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete _brain;
}

/// Functions ///

void	Cat::makeSound() const
{
	std::cout << getType() << " is mewing !" << std::endl;
}

void		Cat::learn(std::string idea)
{
	this->_brain->setIdeas(idea);
}

std::string	Cat::getLearn(int i) const
{
	return (this->_brain->getIdeas(i));
}
