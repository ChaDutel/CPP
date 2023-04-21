#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character : public ICharacter
{
	public :
		Character();
		Character(std::string name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character();

		std::string const & getName() const;
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);

	private :
		AMateria*	_items[4];
		std::string	_name;
};

# endif
