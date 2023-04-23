#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class	Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		virtual ~Brain();

		void		setIdeas(std::string idea);
		std::string	getIdeas(int i) const;

	private :
		std::string	_ideas[100];
};

# endif
