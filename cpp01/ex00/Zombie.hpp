#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <iomanip>
# include <string>

class Zombie
{
	public :
		Zombie(std::string name);
		~Zombie();

		void 		announce(void) const;
		std::string getName(void) const;

	private :
		std::string	_name;
};

Zombie* 	newZombie(std::string name);
void 		randomChump(std::string name);

# endif
