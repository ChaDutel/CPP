#ifndef HARL_HPP
# define HARL_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <iomanip>
# include <string>

class Harl
{
	public :
		Harl();
		~Harl();

		// typedef void (Harl::*PointerArray)();
		// PointerArray	array[4];
		void	complain(std::string level);
		void	switchChoose(int i);
	private :
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
};

# endif
