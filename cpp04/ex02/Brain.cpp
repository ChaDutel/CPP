/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:38:36 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/23 17:45:58 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain construction called\n";
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

/// FUNCTIONS ///

void		Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (_ideas[i] == "")
		{
			_ideas[i] = idea;
			return ;
		}
	}
}

std::string	Brain::getIdeas(int i) const
{
	if (i >= 0 && i < 100)
	{
		if (_ideas[i] == "")
			return ("Empty idea");
		else
			return (_ideas[i]);
	}
	return ("Outside Brain");
}
