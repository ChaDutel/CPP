#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	AMateria;

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& other);
		~MateriaSource();

		void 		learnMateria(AMateria* materia);
		AMateria* 	createMateria(std::string const & type);

	private:
		AMateria	*_materias[4];
};


# endif
