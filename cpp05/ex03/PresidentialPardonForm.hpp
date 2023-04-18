#ifndef PRESIDENtIALPARDONFORM_HPP
# define PRESIDENtIALPARDONFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();

		void		execute(Bureaucrat const & executor) const;
		std::string	getTarget() const;

	private :
		std::string	_target;
};

# endif

