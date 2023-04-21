/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:43:50 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/21 13:35:33 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

/// Builders ///

AMateria::AMateria() : _type("")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria& other)
{
	this->_type = other._type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria()
{
}

/// FUNCTIONS ///

std::string const &		AMateria::getType() const
{
	return (_type);
}

