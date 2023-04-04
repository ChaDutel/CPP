/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:38:36 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/04 18:03:06 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/// Builders ///

Brain::Brain()
{
	std::cout << "Brain construction done\n";
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brain Copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	for (int i = 0; i != 100; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor done\n";
}
