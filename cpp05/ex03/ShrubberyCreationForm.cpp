/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:27:22 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/05/11 16:33:29 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), 145, 137)
{
	this->_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm& other)
{
	out << other.getName() << " sign grade is " << other.getGradeSigned() << ", execute grade is " << other.getGradeExecute() << " and signed status is " << other.getIsSigned();
	return (out);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/// FUNCTIONS ///

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
  if (getIsSigned() == false || executor.getGrade() > getGradeExecute())
	{
		std::cout << "The form isn't signed or ShrubberyCreationForm ";	
		throw GradeTooHighException();
	}



	std::fstream	newtFile;
	std::string		myNewFile;

	myNewFile = getTarget() + "_shrubbery";
	newtFile.open(myNewFile.c_str(), std::ios::out);
	if (!newtFile || newtFile.fail())
	{
		std::cout << "Fail to create file!" << std::endl;
		return ;
	}
	else
	{
		std::cout << "The file created successfully and printed trees!" << std::endl;
		
		newtFile << "						                                 .\n                                              .         ;\n                 .              .              ;%     ;;\n                   ,           ,                :;%  %;                       :         ;                   :;%;'     .,\n            ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'\n                        `@%.  `;@%.      ;@@%;\n                               `@%%. `@%%    ;@@%;\n                                 ;@%. :@%%  %@@%;\n                                  %@bd%%%bd%%:;\n                                  #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '\n                                    %@@@o%;:(.,'\n                              `.. %@@@o%::;\n                                `)@@@o%::;\n                                  %@@(o)::;\n                                     .%@@@@%::;\n                                      ;%@@@@%::;.\n                                       ;%@@@@%%:;;;.\n                          ...;%@@@@@%%:;;;;,..\n";
    newtFile << std::endl;
		newtFile << "						                                 .\n                                              .         ;\n                 .              .              ;%     ;;\n                   ,           ,                :;%  %;                       :         ;                   :;%;'     .,\n            ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'\n                        `@%.  `;@%.      ;@@%;\n                               `@%%. `@%%    ;@@%;\n                                 ;@%. :@%%  %@@%;\n                                  %@bd%%%bd%%:;\n                                  #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '\n                                    %@@@o%;:(.,'\n                              `.. %@@@o%::;\n                                `)@@@o%::;\n                                  %@@(o)::;\n                                     .%@@@@%::;\n                                      ;%@@@@%::;.\n                                       ;%@@@@%%:;;;.\n                          ...;%@@@@@%%:;;;;,..\n";
    newtFile.close();
	}
}

/* "                                                         .
                                              .         ;  
                 .              .              ;%     ;;   
                   ,           ,                :;%  %;   
                    :         ;                   :;%;'     .,   
           ,.        %;     %;            ;        %;'    ,;
             ;       ;%;  %%;        ,     %;    ;%;    ,%'
              %;       %;%;      ,  ;       %;  ;%;   ,%;' 
               ;%;      %;        ;%;        % ;%;  ,%;'
                `%;.     ;%;     %;'         `;%%;.%;'
                 `:;%.    ;%%. %@;        %; ;@%;%'
                    `:%;.  :;bd%;          %;@%;'
                      `@%:.  :;%.         ;@@%;'   
                        `@%.  `;@%.      ;@@%;         
                          `@%%. `@%%    ;@@%;        
                            ;@%. :@%%  %@@%;       
                              %@bd%%%bd%%:;     
                                #@%%%%%:;;
                                %@@%%%::;
                                %@@@%(o);  . '         
                                %@@@o%;:(.,'         
                            `.. %@@@o%::;         
                               `)@@@o%::;         
                                %@@(o)::;        
                               .%@@@@%::;         
                               ;%@@@@%::;.          
                              ;%@@@@%%:;;;. 
                          ...;%@@@@@%%:;;;;,.." */
