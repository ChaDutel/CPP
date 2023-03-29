#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
	public :
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		void			attack(const std::string& target);
		void			printState();
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	getAttackDamage() const;

	private :
		std::string		_name; //son nom, qui sera passé en paramètre d’un constructeur
		unsigned int	_hitPoints; // = 10; //ou points de vie
		unsigned int	_energyPoints; //= 10; //ou points d’énergie
		unsigned int	_attackDamage; //= 0; //ou dommages infligés en attaquant
};

# endif
