#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class	Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int i);
		void		incrementation();
		void		decrementation();
		void		signForm(Form forms);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		Bureaucrat&	operator=(const Bureaucrat& other);
		std::string const	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& other);

# endif
