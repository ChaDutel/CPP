#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


class	AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		AForm	*makeForm(std::string formName, std::string dst);

	private :
		AForm	*switchChoose(int i, std::string dst);
};

std::ostream& operator<<(std::ostream &out, const Intern& other);

# endif
