/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:34:57 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/20 17:38:18 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "IMateriaSource.hpp"

/// Builders ///

IMateriaSource::IMateriaSource()
{
}

IMateriaSource::IMateriaSource(std::string name)
{
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
	this->_name = other._name;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
	// for (int i = 0; i < 4; i++)
	// 	_items[i] = "";

	
	(void)other;
	return (*this);
}

IMateriaSource::~IMateriaSource()
{
}

/// Functions ///

void 		learnMateria(AMateria* materia)
{
	
}


AMateria* 	createMateria(std::string const & type)
{
	
}

learnMateria(AMateria*)
Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
plus tard. Tout comme le IMateriaSource, la MateriaSource peut contenir 4 Materias
maximum. Ces dernières ne sont pas forcément uniques.
• createMateria(std::string const &)
Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment par la MateriaSource et dont le type est le même que celui passé en paramètre. Retourne 0 si le type est inconnu
