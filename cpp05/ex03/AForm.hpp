#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, int gradeSigned, int gradeExecute);
		AForm(const AForm& other);
		virtual ~AForm();

		void			beSigned(const Bureaucrat	&bur);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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
		AForm&	operator=(const AForm& other);

		std::string	const	_name;
		int const			_gradeSigned;
		int	const			_gradeExecute;
		bool				_signed;
};

std::ostream& operator<<(std::ostream &out, const AForm& other);

# endif
