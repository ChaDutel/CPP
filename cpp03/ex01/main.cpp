/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:46:53 by cdutel-l          #+#    #+#             */
/*   Updated: 2023/03/29 18:11:17 by cdutel-l         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	jimin("Jimin");
	ScavTrap	alex("Alex");

	std::cout << std::endl;
	jimin.attack("Alex");
	alex.takeDamage(jimin.getAttackDamage());
	alex.printState();
	std::cout << std::endl;
	
	alex.beRepaired(5);
	alex.printState();
	std::cout << std::endl;

	jimin.printState();
	jimin.attack("Alex");
	alex.takeDamage(jimin.getAttackDamage());
	alex.attack("Jimin");
	jimin.takeDamage(alex.getAttackDamage());
	jimin.printState();
	alex.printState();
	std::cout << std::endl;

	jimin.attack("Alex");
	jimin.printState();
	std::cout << std::endl;
	jimin.attack("Alex");
	alex.attack("Jimin");
	jimin.takeDamage(alex.getAttackDamage());
	alex.printState();
	jimin.printState();
	jimin.attack("Alex");
	jimin.printState();
	std::cout << std::endl;
	return (0);
}
