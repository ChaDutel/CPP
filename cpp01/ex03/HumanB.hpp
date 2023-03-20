#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class    HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();

		Weapon          *weapon;
		void            setWeapon(Weapon &weapon);
		void            attack();
		std::string     getName() const;
		void            setName(std::string name);

	private:
		std::string    _name;
};

#endif
