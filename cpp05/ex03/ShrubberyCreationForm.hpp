#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

		void		execute(Bureaucrat const & executor) const;
		std::string	getTarget() const;

	private :
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		std::string	_target;
};

# endif

