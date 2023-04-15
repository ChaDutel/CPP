#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(Bureaucrat bur);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

		void	execute(Bureaucrat const & executor) const;

	private :
		std::string	_target;
};

# endif


// ShrubberyCreationForm (formulaire de création d'arbustes) :
// Échelons requis : signature 145, exécution 137
// Créé un fichier <target>_shrubbery dans le répertoire courant, et écrit des arbres
// ASCII à l’intérieur.
// • RobotomyRequestForm (formulaire de demande de robotomie) :
// Échelons requis : signature 72, exécution 45
// Fait des bruits de perceuse. Ensuite, informe que la <target> a été robotomisée
// avec succès 50% du temps. Dans le cas contraire, informe que l’opération a échoué.
// • PresidentialPardonForm (formulaire de pardon présidentiel) :
// Échelons requis : signature 25, exécution 5
// Informe que la <target> a été pardonnée par Zaphod Beeblebrox.
