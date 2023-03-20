#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <iomanip>
# include <string>

class Zombie
{
	public :
		Zombie();
		~Zombie();

		void 		announce(void) const;
		void		setName(std::string name);
		std::string getName(void) const;

	private :
		std::string	_name;
};

Zombie* zombieHorde(int N, std::string name);

# endif
