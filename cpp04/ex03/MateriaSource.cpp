/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:24:09 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/21 13:40:04 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

/// Builders ///

MateriaSource::MateriaSource()
{
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	(void)other;
	return (*this);
}

MateriaSource::~MateriaSource()
{
}

/// Functions ///

void 		MateriaSource::learnMateria(AMateria* materia)
{
	*_materias = materia;
}


AMateria* 	MateriaSource::createMateria(std::string const & type)
{
	// AMateria	cpMateria = new AMateria._materias[i]();
	for (int i = 0; _materias[i]; i++)
	{
		if (_materias[i]->getType() == type)
			return (_materias[i]->clone());
		// AMateria	*cpMateria = this->*_materias[i].clone();
	}
	
	// AMateria	*cpMateria = this->_materias[0].clone();
	return (0);
}

// learnMateria(AMateria*)
// 	Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
// 	plus tard. Tout comme le IMateriaSource, la MateriaSource peut contenir 4 Materias
// 	maximum. Ces dernières ne sont pas forcément uniques.
// • createMateria(std::string const &)
// 	Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment par la MateriaSource et dont le type est le même que celui passé en paramètre. Retourne 0 si le type est inconnu
