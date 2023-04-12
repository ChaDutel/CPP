#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(std::string name, int gradeSigned, int gradeExecute);
		Form(const Form& other);
		~Form();

		void		beSigned(const Bureaucrat	&bur);

		// Getters //
		std::string	getName() const;
		int			getGradeSigned() const;
		int			getGradeExecute() const;
		bool		getIsSigned() const;

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
		Form&	operator=(const Form& other);

		std::string	const	_name;
		int const			_gradeSigned;
		int	const			_gradeExecute;
		bool				_signed;
};

std::ostream& operator<<(std::ostream &out, const Form& other);

# endif
