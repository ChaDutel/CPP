/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:57:16 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/21 16:44:31 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

/// Builders ///

Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(const Ice& other) : AMateria()
{
	this->_type = "ice";
	(void)other;
}

Ice& Ice::operator=(const Ice& other)
{
	(void)other;
	return (*this);
}

Ice::~Ice()
{
}

/// FUNCTIONS ///

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*		Ice::clone() const
{
	AMateria	*cpIce = new Ice();
	return (cpIce);
}
