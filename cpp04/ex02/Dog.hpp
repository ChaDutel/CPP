#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal
{
	public :
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();

		void		makeSound() const;
		void		learn(std::string idea);
		std::string	getLearn(int i) const;

	private :
		Brain *_brain;
};

# endif
