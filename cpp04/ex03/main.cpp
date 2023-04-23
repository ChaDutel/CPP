/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:26:06 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/04/23 13:46:04 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"
# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

int main()
{

	std::cout << "SUBJECT TEST  //////////////////\n" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "\nOWN TEST  //////////////////\n" << std::endl;
	
	ICharacter *myChar = new Character("King");
	IMateriaSource *power = new MateriaSource();
	AMateria	*cureBis;
	
	cureBis = power->createMateria("cure");
	power->createMateria("bouh");

	power->learnMateria(new Cure());
	cureBis = power->createMateria("cure");

	myChar->equip(cureBis);
	myChar->use(0, *myChar);
	myChar->unequip(0);

	delete power;
	delete myChar;
	
	return (0);
	
}
