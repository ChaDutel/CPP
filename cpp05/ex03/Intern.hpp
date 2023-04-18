#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class	AForm;

class Intern
{
	public:
		Intern();
		Intern(std::string name, int grade);
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern();

		AForm	*makeForm(std::string formName, std::string dst);
};

std::ostream& operator<<(std::ostream &out, const Intern& other);

# endif
