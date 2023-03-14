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
		void		setName(std::string name);
		std::string getName(void);
		Zombie*		getNewZombie(std::string name);
		void 		randomChump(std::string name);

	private :
		std::string	_name;
		Zombie* 	_newZombie(std::string name);
};

# endif
