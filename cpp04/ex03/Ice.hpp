#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"

class	Ice
{
	public :
		Ice();
		Ice(const Ice& other);
		Ice&	operator=(const Ice& other);
		~Ice();

		void	use(ICharacter&);
	private :
		std::string	_type = "ice";
};

#endif
