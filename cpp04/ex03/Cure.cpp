/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:53:15 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/21 16:14:45 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

/// Builders ///

Cure::Cure()
{
	this->_type = "cure";
}

Cure::Cure(const Cure& other) : AMateria()
{
	this->_type = "cure";
	(void)other;
}

Cure& Cure::operator=(const Cure& other)
{
	(void)other;
	return (*this);
}

Cure::~Cure()
{
}

/// FUNCTIONS ///

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*		Cure::clone() const
{
	AMateria	*cpCure = new Cure();
	return (cpCure);
}
