/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:34:57 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/20 17:44:31 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "IMateriaSource.hpp"

/// Builders ///

IMateriaSource::IMateriaSource()
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

void 		IMateriaSource::learnMateria(AMateria* materia)
{
	*_materias[i] = materia;
}


AMateria* 	IMateriaSource::createMateria(std::string const & type)
{
	AMateria	cpMateria = new AMateria._materias[i]();
	return (cpMateria);
}

learnMateria(AMateria*)
Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
plus tard. Tout comme le IMateriaSource, la MateriaSource peut contenir 4 Materias
maximum. Ces dernières ne sont pas forcément uniques.
• createMateria(std::string const &)
Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment par la MateriaSource et dont le type est le même que celui passé en paramètre. Retourne 0 si le type est inconnu
