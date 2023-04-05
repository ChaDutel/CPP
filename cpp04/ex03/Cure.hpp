#ifndef CURE_HPP
# define CURE_HPP

# include "ICharacter.hpp"

class	Cure
{
	public :
		Cure();
		Cure(const Cure& other);
		Cure&	operator=(const Cure& other);
		~Cure();

		void	use(ICharacter&);
		//  clone()

	private :
		std::string	_type = "cure";
};

#endif
