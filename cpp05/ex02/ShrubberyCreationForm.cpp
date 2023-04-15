/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:27:22 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/15 19:03:51 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat bur) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = bur.getName();
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
	out << other.getName() << " " << other.getGradeSigned() << " " << other.getGradeExecute() << " " << other.getIsSigned();
	return (out);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::fstream	newtFile;
	std::string		myNewFile;

	myNewFile = executor.getName() + "_shrubbery";
	newtFile.open(myNewFile.c_str(), std::ios::out);
	if (!newtFile || newtFile.fail())
	{
		std::cout << "Fail to create file!" << std::endl;
		return ;
	}
	else
	{
		std::cout << "The replace file created successfully!" << std::endl;
		
		newtFile << "						                                 .\n                                              .         ;\n                 .              .              ;%     ;;\n                   ,           ,                :;%  %;                       :         ;                   :;%;'     .,\n            ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'\n                        `@%.  `;@%.      ;@@%;\n                               `@%%. `@%%    ;@@%;\n                                 ;@%. :@%%  %@@%;\n                                  %@bd%%%bd%%:;\n                                  #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '\n                                         %@@@o%;:(.,'\n                                 `.. %@@@o%::;\n                                   `)@@@o%::;\n                                       %@@(o)::;\n                                     .%@@@@%::;\n                                      ;%@@@@%::;.\n                                       ;%@@@@%%:;;;.\n                          ...;%@@@@@%%:;;;;,..\n";
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

						  
// "						                                 .\n                                              .         ;\n                 .              .              ;%     ;;\n                   ,           ,                :;%  %;                       :         ;                   :;%;'     .,\n            ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'\n                        `@%.  `;@%.      ;@@%;\n                               `@%%. `@%%    ;@@%;\n                                 ;@%. :@%%  %@@%;\n                                  %@bd%%%bd%%:;\n                                  #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '\n                                         %@@@o%;:(.,'\n                                 `.. %@@@o%::;\n                                   `)@@@o%::;\n                                       %@@(o)::;\n                                     .%@@@@%::;\n                                      ;%@@@@%::;.\n                                       ;%@@@@%%:;;;.\n                          ...;%@@@@@%%:;;;;,..\n"
