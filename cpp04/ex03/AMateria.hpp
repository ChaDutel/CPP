#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class	ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria&	operator=(const AMateria& other);
		virtual ~AMateria();


		std::string const &		getType() const;
		virtual AMateria*		clone() const = 0;
		virtual void			use(ICharacter& target) = 0;

	protected:
		std::string	_type;
	private:
		AMateria(const AMateria& other);
};

# endif
