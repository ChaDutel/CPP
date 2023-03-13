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

	private :
		std::string	name;
		Zombie* 	newZombie(std::string name);
		void 		randomChump(std::string name) const;
};

# endif
