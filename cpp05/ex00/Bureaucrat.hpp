#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int i);
		void			incrementation(int i);
		void			decrementation(int i);

	private:
		std::string			_name;
		int					_grade;
};

// Bureaucrat::GradeTooHighException ou Bureaucrat::GradeTooLowException
std::ostream& operator<<(std::ostream &out, const Bureaucrat& other);

# endif
