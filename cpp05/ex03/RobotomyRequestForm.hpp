#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

		void		execute(Bureaucrat const & executor) const;
		std::string	getTarget() const;

	private :
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		std::string	_target;
};

# endif
